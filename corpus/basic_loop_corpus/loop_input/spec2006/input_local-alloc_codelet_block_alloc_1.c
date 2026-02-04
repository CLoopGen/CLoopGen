#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int next_qty;
int i;
int *qty_order;

void init_vars() {
    next_qty = 25000000;  // Approximately 100MB of data (25M integers * 4 bytes)
    qty_order = (int*)malloc(next_qty * sizeof(int));
    if (!qty_order) {
        exit(1);
    }
}