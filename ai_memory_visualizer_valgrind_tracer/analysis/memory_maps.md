# AI Memory Visualizer

## 1. Compilation

The programs were initially compiled using `make`.

The compilation failed because `-Werror` treated the use-after-free warnings as errors.

I compiled `aliasing_example.c` again without `-Werror`, allowing the program to compile while keeping the warnings visible.

The original source code was not modified. Successful compilation of `stack_example.c` using the Makefile was not confirmed.

## 2. Execution without Valgrind

Both mandatory programs were executed normally.

- `./stack_example`: displayed four recursion depths (0 to 3), with different local variables and memory addresses.
- `./aliasing_example`: showed that two pointers can share the same memory address. After `free(a)`, reading `b[2]` returned an unexpected value (1269288402), and writing to `b[3]` appeared to succeed.

The absence of a crash does not mean that the memory accesses were valid.

## 3. Key execution points

### Function entry and exit

- `stack_example.c`: each function call has its own local variables. Their lifetime ends when the function returns.
- `aliasing_example.c`: when `make_numbers()` returns, its local variables disappear, but the allocated array remains valid.

### Recursive calls

In `stack_example.c`, line 26 calls `walk_stack()` recursively until depth 3 is reached.

Each call has its own `marker` variable. The functions return in reverse order: 3, 2, 1, 0.

There is no recursion in `aliasing_example.c`.

### Heap allocation and deallocation

In `aliasing_example.c`:

- Line 12: `malloc()` allocates memory for five integers.
- Lines 16–17: the array is initialized.
- Line 38: `free(a)` releases the allocated memory.
- Lines 40–45: the program uses a dangling pointer.

There is no explicit heap allocation in `stack_example.c`.

### Pointer assignments and reassignments

- `stack_example.c`, line 7: `p_local = &local_int` stores the address of a local integer.
- `aliasing_example.c`, line 12: `arr` receives the allocated memory address.
- Line 30: `a` receives the address returned by `make_numbers()`.
- Line 34: `b = a` creates an alias. Both pointers reference the same array.

## 4. Step-by-step memory maps

### 4.1. Stack frames and local variables

Each recursive call creates a separate function instance.

At maximum recursion depth, between calls to `dump_frame()`:

```text
STACK
+----------------------+
| depth = 3, marker=30 |
| depth = 2, marker=20 |
| depth = 1, marker=10 |
| depth = 0, marker=0  |
| main()               |
+----------------------+
```

Each frame belongs to a different `walk_stack()` call.

The variables `local_int`, `local_buf` and `p_local` belong to `dump_frame()` and reach the end of their lifetime each time it returns.

### 4.2. Heap allocations

After `malloc()` and array initialization:

```text
STACK          HEAP
arr ---------> [0][11][22][33][44]
```

After `make_numbers()` returns:

```text
STACK          HEAP
a -----------> [0][11][22][33][44]
b = NULL
```

The local pointer `arr` no longer exists, but the allocated array remains valid.

### 4.3. Pointer values and aliases

After `b = a`:

```text
STACK          HEAP
a -----+
       +-----> [0][11][22][33][44]
b -----+
```

Both pointers contain the same address:

`0x58adc9f3b420`

There are two pointers but only one allocation.

After `free(a)`:

```text
STACK          FORMER HEAP BLOCK
a ----X
              [FREED MEMORY]
b ----X
```

Both pointers become dangling pointers. Their values are indeterminate, and they must not be used to access the former array.

### 4.4. Object lifetimes

| Object | Lifetime |
|---|---|
| `marker` | Until `walk_stack()` returns |
| `local_int` | Until `dump_frame()` returns |
| `local_buf` | Until `dump_frame()` returns |
| `p_local` | Until `dump_frame()` returns |
| `arr` | Until `make_numbers()` returns |
| `a` and `b` | Until `main()` returns |
| Allocated array | From `malloc()` to `free()` |

## 5. Critical review of AI-generated explanations

The AI-generated memory maps were useful for understanding memory management. However, some explanations were incomplete or oversimplified.

| Topic | AI limitation |
|---|---|
| Recursion | The AI did not initially distinguish the lifetimes of `walk_stack()` and `dump_frame()` variables. |
| Stack memory | The diagrams suggested that all local variables are physically stored on the stack. |
| Dangling pointers | The AI initially focused on invalid reads and writes without mentioning the use of the dangling pointer at line 40. |
| Uninitialized memory | The AI initially omitted the 14 uninitialized elements of `local_buf`. |
| Compilation | Successful execution did not confirm successful compilation using the Makefile. |
| Undefined behavior | The observed output alone cannot prove that memory accesses are valid. |

## 6. Correction of inaccuracies

### 6.1. Variable lifetimes

`dump_frame()` returns before the next recursive call begins. Its local variables are therefore no longer alive during deeper recursive calls, unlike the variables of `walk_stack()`.

### 6.2. Stack representation

Local variables have automatic storage duration. However, C does not guarantee that they are physically stored on the stack. The memory maps are simplified representations.

### 6.3. Dangling pointers

After `free(a)`, both `a` and `b` have indeterminate pointer values because they referenced the same allocation.

A possible correction would be:

```c
free(a);
a = NULL;
b = NULL;
```

Any subsequent access through these pointers must also be removed or prevented.

### 6.4. Uninitialized memory

`local_buf` contains 16 elements, but only the first two are initialized.

```text
Index:  0    1    2         15
       [A] [\0] [?] [...] [?]
```

The remaining 14 elements have indeterminate values.

### 6.5. Compilation

The initial Makefile compilation failed because of `-Werror`. Removing this flag allowed `aliasing_example.c` to compile without correcting its intentional memory errors.

### 6.6. Undefined behavior

Reading or writing freed memory causes undefined behavior. The program may crash, display unexpected values or appear to work normally.

Successful execution does not guarantee correct memory management.

### Conclusion

AI is useful for understanding and visualizing memory, but its explanations must be checked against the source code and reliable technical documentation. Simplified explanations can omit important details and lead to incorrect assumptions.