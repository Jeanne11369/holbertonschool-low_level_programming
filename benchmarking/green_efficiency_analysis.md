# Green Tech Efficiency & Benchmarking Lab
This project introduces benchmarking : running C programs, measuring execution time, comparing implementations, and reasoning what the results mean in terms of efficiency and sustainability.

## 1. Measurement Methodology
Three experiments were conducted using the provided C source files. All programs were compiled with the required GCC flags:

`-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`

### Calculation Methods
In baseline_loop.c, a calculation was repeated 100 million times. We ran the program three times, then added the times and divided by three to find the average.

In comparison_algorithms.c, we compared nested loops (naive) with one loop (single pass). We ran each version at least three times, then divided their average times to see how much longer one took.

In instrumentation_lab.c, we timed three steps: creating data, processing it, and calculating a checksum. Each step’s percentage was its time divided by the total time, multiplied by 100.

We measured CPU time using clock() from <time.h> and divided by CLOCKS_PER_SEC to get seconds.

## 2. Observed Performance Differences

### Baseline Measurement
The baseline experiment produced the following execution times:

- Run 1: 1.177335 sec;
- Run 2: 1.176947 sec;
- Run 3: 1.177463 sec;

The average execution time was 1.177248 seconds.

### Algorithmic Comparison
The average execution times were:

- Naive algorithm: 1.665235 seconds
- Single-pass algorithm: 0.000079 seconds

The naive version took about 21,079 times as much CPU time as the single-pass version. However, they produce different results, so this is not a fair comparison of two ways to solve the same problem.

### Instrumentation Experiment

The measured CPU times were:

- BUILD_DATA: 0.000388 seconds
- PROCESS: 0.000384 seconds
- REDUCE: 0.000196 seconds
- TOTAL: 0.000973 seconds

The phase consuming the most CPU time was Building Data with approximately 39% of the total measured execution time.

## 3. Relation Between Runtime and Energy Consumption

Using less CPU time may save energy, but it is not guaranteed. Energy use also depends on the hardware and how the system runs.

We only measured CPU time, so we cannot calculate how much energy was saved.


## 4. Limitations of the Experiment
There are a few things to keep in mind when looking at these results.

CPU time does not tell us the total time a program takes or how much energy it uses. Measurements can also vary between runs.

The two versions produce different results, so the comparison is not fully fair. 

We also tested on only one system, so results may differ on other computers.

## 5. Practical Engineering Takeaway

What I learned from this project is that measuring performance before making changes has its importance. Timing each part helps show where improvements may be needed and how algorithm choices affect speed.

Good benchmarking is obtained while testing under similar conditions and through an understanding of the results. CPU time alone cannot tell us energy use, but it can help us write more efficient code.