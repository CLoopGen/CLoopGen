#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t j;
unsigned int K[64];
unsigned int A;
unsigned int B;
unsigned int C;
unsigned int D;
unsigned int E;
unsigned int F;
unsigned int G;
unsigned int H;
unsigned int T1;
unsigned int T2;
unsigned int W[64];

void init_vars() {
    // Initialize scalar variables to non-zero values to ensure meaningful computation
    A = 0x6a09e667U;
    B = 0xbb67ae85U;
    C = 0x3c6ef372U;
    D = 0xa54ff53aU;
    E = 0x510e527fU;
    F = 0x9b05688cU;
    G = 0x1f83d9abU;
    H = 0x5be0cd19U;

    // Initialize K and W arrays with pseudo-random deterministic values
    for (int i = 0; i < 64; i++) {
        K[i] = ((unsigned int)(0x428a2f98U + i * 0x3b6a0965U)) ^ 0xdeadbeefU;
        W[i] = ((unsigned int)(0x12345678U + i * 0xabcdef01U)) ^ 0xcafebabeU;
    }

    // Initialize temporary variables to zero
    T1 = 0;
    T2 = 0;
    j = 0;
}