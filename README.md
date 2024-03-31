# A kernel in C and x86-64 Assembly that performs a dot product between vector A and vector B.
## Performance of the Kernels
Each implementation was run 30 times for vector sizes n = 2<sup>20</sup>, 2<sup>24</sup>, and 2<sup>30</sup>, and the average execution time was calculated. This includes a C version and an x86-64 assembly language version.

### C Kernel (`cfunc.c` file)

`dot_prod_c(double A[], double B[], long long int n)`

| n    | ave time      |
|------|---------------|
| 2^20 | #.###### sec  |
| 2^24 | #.###### sec  |
| 2^30 | #.###### sec  |
|      | = #.###### sec|

### x86-64 Kernel (`asmfunc.asm` file)
`dot_prod_asm(double A[], double B[], long long int n)`

| n    | ave time      |
|------|---------------|
| 2^20 | #.###### sec  |
| 2^24 | #.###### sec  |
| 2^30 | #.###### sec  |
|      | = #.###### sec|

The x86-64 implementation had a lower average execution time than the C implementation for the dot product operation. This suggest that the x86-64 runs faster than the C implementation.

## Correctness Check of Dot Product
### Dot Product from C vs. Dot Product from x86-64
*insert screenshot*

✔ produces the same results
