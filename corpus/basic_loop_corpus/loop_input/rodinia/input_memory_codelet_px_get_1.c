#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

int size;
PERM *permute;
int i;

void init_vars() {
    size = 64 * 1024 * 1024 / sizeof(u_int); // ~256MB / sizeof(u_int) ≈ 64M elements
    permute = (PERM *)malloc(sizeof(PERM));
    if (!permute) exit(1);
    permute->size = size;
    permute->max_size = size;
    permute->pe = (u_int *)malloc(size * sizeof(u_int));
    if (!permute->pe) exit(1);
}