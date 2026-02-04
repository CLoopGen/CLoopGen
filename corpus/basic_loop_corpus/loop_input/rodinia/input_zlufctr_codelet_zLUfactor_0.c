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
    m = 64 * 1024 * 1024 / sizeof(u_int);  // ~256MB of data for pe array
    pivot = (PERM *)malloc(sizeof(PERM));
    if (!pivot) exit(1);
    pivot->pe = (u_int *)malloc(m * sizeof(u_int));
    if (!pivot->pe) exit(1);
    pivot->size = 0;
    pivot->max_size = m;
}