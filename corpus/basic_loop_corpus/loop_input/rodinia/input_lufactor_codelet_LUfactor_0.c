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
u_int i;
u_int m;

void init_vars() {
    m = 65536; // Size to target ~0.01 sec runtime (approx 256KB of data)

    pivot = (PERM *)malloc(sizeof(PERM));
    if (!pivot) exit(1);

    pivot->size = 0;
    pivot->max_size = m;
    pivot->pe = (u_int *)malloc(m * sizeof(u_int));
    if (!pivot->pe) exit(1);
}

// Ensure symbols are defined and accessible for loop()