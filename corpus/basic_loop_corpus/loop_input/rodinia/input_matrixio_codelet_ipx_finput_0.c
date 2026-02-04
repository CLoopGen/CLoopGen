#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct {
    u_int size;
    u_int max_size;
    u_int *pe;
} PERM;

u_int i = 1000000;  // Approx. 4MB of data (1e6 * 4 bytes)
u_int j;
u_int entry = 42;
u_int ok = 1;

PERM *px;

void init_vars() {
    px = (PERM*)malloc(sizeof(PERM));
    if (!px) exit(1);
    px->size = i;
    px->max_size = i;
    px->pe = (u_int*)malloc(i * sizeof(u_int));
    if (!px->pe) exit(1);

    for (u_int idx = 0; idx < i; idx++) {
        px->pe[idx] = (idx % 1000) + 1;
    }
}