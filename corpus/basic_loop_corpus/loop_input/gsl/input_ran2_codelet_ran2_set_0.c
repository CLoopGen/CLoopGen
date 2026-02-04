#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

long m1 = 2147483647L;    // Large prime modulus (e.g., 2^31 - 1)
long a1 = 16807L;         // Common multiplier for LCG
long q1 = 127773L;         // m1 / a1 (precomputed for Schrage's method)
long r1 = 2836L;           // m1 % a1 (precomputed for Schrage's method)
unsigned long s = 123456789UL;
int i;

void init_vars() {
    // No additional initialization needed; scalar variables are already initialized at file scope.
    // The values are chosen to ensure valid arithmetic in the loop and avoid overflow issues.
}