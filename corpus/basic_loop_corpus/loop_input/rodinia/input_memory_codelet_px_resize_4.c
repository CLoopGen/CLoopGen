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
    new_size = 65536; // Approximately 256KB of data (65536 * sizeof(u_int) = 256KB)

    px = (PERM *)malloc(sizeof(PERM));
    if (!px) {
        exit(1);
    }

    px->size = 0;
    px->max_size = new_size;
    px->pe = (u_int *)malloc(new_size * sizeof(u_int));
    if (!px->pe) {
        free(px);
        exit(1);
    }
}