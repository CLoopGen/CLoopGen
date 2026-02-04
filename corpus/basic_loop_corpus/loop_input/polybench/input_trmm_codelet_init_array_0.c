#include <stdio.h>
#include <inttypes.h>

int m = 1000;
int n = 1200;
double A[1000][1000];
double B[1000][1200];
int i;
int j;

void init_vars() {
    // No additional initialization needed beyond static definitions
    // Arrays and scalars are already zero-initialized if not explicitly set
    // Loop bounds m=1000, n=1200 ensure all array accesses are in bounds
}