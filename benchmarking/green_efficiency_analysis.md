# Green Tech Efficiency & Benchmarking Lab
This project introduces benchmarking as an engineering practice: running predefined C programs, measuring execution time, comparing implementations, and reasoning what the results mean in terms of efficiency and sustainability.

## 1. Measurement Methodology
Three experiments were conducted using the provided C source files. All programs were compiled with the required GCC flags:

`-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`

### Calculation Methods
The first experiment, `baseline_loop.c`, executed a deterministic calculation 100 million times. The program was executed three times to observe possible timing variations. The average execution time was obtained by adding the three recorded execution times and dividing their sum by three.

The second experiment, `comparison_algorithms.c`, compared two implementations: a naive algorithm using nested loops and a single-pass algorithm using one loop. Both implementations were measured during at least three executions. To compare algorithm performance, the naive algorithm's average execution time was divided by the single-pass algorithm's average execution time.

The third experiment, `instrumentation_lab.c`, involved adding timing instrumentation to three processing phases: building a dataset, processing its elements, and calculating a checksum. Here, each processing phase's percentage was calculated by dividing its execution time by the total measured CPU time and multiplying by 100.

CPU execution times were measured using `clock()` from `<time.h>`, with the results converted into seconds using `CLOCKS_PER_SEC`.

## 2. Observed Performance Differences

### Baseline Measurement
The baseline experiment produced the following execution times:

- Run 1: 1.177335 seconds
- Run 2: 1.176947 seconds
- Run 3: 1.177463 seconds

The average execution time was 1.177248 seconds.

### Algorithmic Comparison
The average execution times were:

- Naive algorithm: 1.665235 seconds
- Single-pass algorithm: 0.000079 seconds

The measured execution-time ratio was 21,078.
This makes the Naive algorithm approximately 21,078 times longer than the single-pass.

An important distinction is that the provided implementations do not calculate identical results. Therefore, the measurements compare their execution costs but do not establish a fair performance comparison between equivalent algorithms.

### Instrumentation Experiment

The measured CPU times were:

- BUILD_DATA: 0.000388 seconds
- PROCESS: 0.000384 seconds
- REDUCE: 0.000196 seconds
- TOTAL: 0.000973 seconds

The phase consuming the most CPU time was Building Data, accounting for approximately 39% of the total measured execution time.

## 3. Relation Between Runtime and Energy Consumption

Execution time is relevant to energy efficiency because processing operations require computational resources.
Under comparable conditions, reducing CPU activity can potentially reduce energy consumption, however, shorter CPU execution time does not automatically guarantee lower energy consumption. Eergy usage also depends on hardware characteristics, processor power, memory activity, and system configuration.

Since this project measured CPU time rather than electrical power, no quantitative conclusion about energy savings can be established.

## 4. Limitations of the Experiment
There are a few things to keep in mind when looking at these results.

First, when measuring CPU time, it doesn't tell us exactly how long a program takes in real time or how much energy it actually uses.
Execution times can also change slightly depending on what's happening on the computer, like other programs running in the background or how accurately the system measures time.

Another important point is that the two algorithms we compared don't do exactly the same amount of work therefore don't return the same result comparatively, so it's not a completely fair comparison.

Finally, since all the tests were done in the same environment, we can't assume we'd get the same results on a different computer.Several limitations affect the interpretation of these results.

## 5. Practical Engineering Takeaway

What I learned from this project is that measuring performance is an important step before trying to make a program more efficient.

By comparing execution times and looking at each part of a program separately, it's easier to see where most of the processing time goes and what might need improvement.

I also got a better understanding of how the way an algorithm is written can make a big difference in its performance.

My main takeaway is that good benchmarking is about testing under consistent conditions, understanding what those numbers mean, and using them to make better decisions.

Even though execution time doesn't directly tell us how much energy a program consumes, it's still a useful starting point for writing more efficient and potentially more sustainable code.