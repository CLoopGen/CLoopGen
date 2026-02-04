#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

PERM *px;
u_int i;
u_int j;
u_int entry;
u_int ok;

void init_vars() {
    i = 1000000; // Approximate size for ~0.01 sec runtime (adjustable based on system)
    px = (PERM *)malloc(sizeof(PERM));
    if (!px) exit(1);
    px->size = i;
    px->max_size = i;
    px->pe = (u_int *)malloc(i * sizeof(u_int));
    if (!px->pe) exit(1);

    for (u_int idx = 0; idx < i; idx++) {
        px->pe[idx] = idx + 1; // Initialize with non-matching values
    }

    entry = 2000000; // Ensure this is different from all px->pe[j] to keep `ok` evaluation meaningful
    ok = 1; // Initial value for reduction operation
}