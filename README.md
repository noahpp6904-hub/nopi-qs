# nopi-qs
Nonstandard Programing Implementation of Quicksort

## Quicksort: From Classical to Modern Implementations
Examination of quicksort, starting from a standard recursive and in-place implementation, followed by a better pivot selection and modern optimizations such as SIMD operations, multi-threading an dynamic resource management.

## Roadmap

RECURSIVE
- [x] Basic implementation
- [x] Comparison function
- [ ] Benchmark function
- [ ] Timer function

PARTITIONING
- [x] Hoare
- [ ] Lomuto
- [ ] 3-Way
- [ ] Bentley-McIlroy

PIVOT SELECTION
- [x] Middle element
- [ ] Random element
- [ ] Best of 3
- [ ] Median from sample

CPU OPTIMIZATIONS
- [ ] Reduce swaps
- [ ] Branch prediction
- [ ] Block partitioning
- [ ] SIMD compariosn

MULTI-THREADING
- [ ] PThreads implementation
- [ ] OpenMP implementation
- [ ] Thread-Pool
- [ ] Resource Monitor

BENCHMARKING
- [x] Random data
- [ ] Random with no unique elements
- [ ] Reverse-sorted data
- [ ] Nearly sorted data
- [ ] Duplicate-heavy data
- [ ] Different input sizes
- [ ] Different integer types
- [ ] Measure execution time
- [ ] Measure memory usage
- [ ] Measure cache misses
- [ ] Measure branch predictions

## Results of benchmarking

I will use qsort() from <stdlib.h> as the baseline for all implementations.
For each benchmark critira, I will provide a graph comparing the different implementatios across varying input size. This will show the impact of each optimization and overall performance. 

## Results of analysis
