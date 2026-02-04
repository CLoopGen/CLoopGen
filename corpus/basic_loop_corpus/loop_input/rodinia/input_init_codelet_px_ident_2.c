#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int i;
int px_size;
u_int *px_pe;

void init_vars() {
    px_size = 64 * 1024 * 1024 / sizeof(u_int);
    px_pe = (u_int*)calloc(px_size, sizeof(u_int));
    if (!px_pe) {
        exit(1);
    }
}