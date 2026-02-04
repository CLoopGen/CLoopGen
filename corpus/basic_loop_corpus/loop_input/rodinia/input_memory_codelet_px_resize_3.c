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
int new_size;
int i;

void init_vars() {
    new_size = 65536; // ~256KB of data: 65536 elements * 4 bytes = 256KB
    px = (PERM *)malloc(sizeof(PERM));
    if (!px) exit(1);
    px->size = new_size / 2; // Start halfway
    px->max_size = new_size;
    px->pe = (u_int *)calloc(new_size, sizeof(u_int));
    if (!px->pe) exit(1);
}