#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

PERM *pivot;
int i;
int n;

void init_vars() {
    n = 64 * 1024 * 1024 / sizeof(u_int);  // ~256MB of data for u_int array
    pivot = (PERM *)malloc(sizeof(PERM));
    if (!pivot) exit(1);
    pivot->size = 0;
    pivot->max_size = n;
    pivot->pe = (u_int *)malloc(n * sizeof(u_int));
    if (!pivot->pe) exit(1);
}

// End of file