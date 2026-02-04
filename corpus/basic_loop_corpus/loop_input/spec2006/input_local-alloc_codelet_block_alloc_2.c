#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int next_qty;
int i;
int *qty_order;

void init_vars() {
    next_qty = 64 * 1024 * 1024; // 64M elements, roughly 256MB for int array
    qty_order = (int*)calloc(next_qty, sizeof(int));
    if (!qty_order) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}