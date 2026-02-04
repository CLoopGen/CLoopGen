#include <stdio.h>

typedef int boolean;

int n = 1000000;  // Sufficient size to take ~0.01 seconds

int rowstr[1000001];  // Index from 1 to n, so size n+1
boolean mark[1000001];  // Same size as rowstr
int j;  // Must be defined since it's used in loop and declared extern

void init_vars() {
    // No additional initialization needed beyond zeroed arrays
    // Global arrays are zero-initialized by default
}