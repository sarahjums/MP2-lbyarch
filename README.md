# A kernel in C and x86-64 Assembly that performs a dot product between vector A and vector B.
## Performance of the Kernels (debug mode)
Each implementation was run 30 times for vector sizes n = 2<sup>20</sup>, 2<sup>24</sup>, and 2<sup>30</sup>, and the average execution time was calculated. This includes a C version and an x86-64 assembly language version.

### C Kernel (`cfunc.c` file)

`dot_prod_c(...)`

| n    | ave time       |
|------|----------------|
| 2<sup>20</sup> | 0.003267  sec  |
| 2<sup>24</sup> | 0.051800  sec  |
| 2<sup>30</sup> | 64.089600 sec  |

### x86-64 Kernel (`asmfunc.asm` file)
`dot_prod_asm(...)`

| n    | ave time       |
|------|----------------|
| 2<sup>20</sup> | 0.000967  sec  |
| 2<sup>24</sup> | 0.015400  sec  |
| 2<sup>30</sup> | 62.540967 sec  |

The x86-64 implementation had a lower average execution time than the C implementation for the dot product operation. This suggest that the x86-64 runs faster than the C implementation.

## Correctness Check of Dot Product
### Dot Product from C vs. Dot Product from x86-64
![image](https://github.com/sarahjums/MP2-lbyarch/assets/106684744/0d7aaa29-2421-4242-bb9a-cb74612fc604)

✔ produces the same results

NOTE: displayed times are an average from 30 consecutive runs

## Performance of the Kernels (release mode)

### C Kernel (`cfunc.c` file)

`dot_prod_c(...)`

| n    | ave time       |
|------|----------------|
| 2<sup>20</sup> | 0.000933  sec  |
| 2<sup>24</sup> | 0.014800  sec  |
| 2<sup>30</sup> | 66.016167 sec  |

### x86-64 Kernel (`asmfunc.asm` file)
`dot_prod_asm(...)`

| n    | ave time       |
|------|----------------|
| 2<sup>20</sup> | 0.000933  sec  |
| 2<sup>24</sup> | 0.014533  sec  |
| 2<sup>30</sup> | 64.533533 sec  |

Similar to the trials performed in debug mode, the x86-64 implementation once again had a lower average execution time than the C implementation for the dot product operation. This further supports the idea that the x86-64 implementation is a better performing one.

## Correctness Check of Dot Product
### Dot Product from C vs. Dot Product from x86-64
![image](https://github.com/sarahjums/MP2-lbyarch/assets/106684744/981fddff-7943-4829-be42-2ca5bdb7039f)

✔ produces the same results
