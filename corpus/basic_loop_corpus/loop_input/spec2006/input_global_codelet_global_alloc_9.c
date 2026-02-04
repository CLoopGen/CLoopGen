#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

size_t i;
int max_allocno = 65536;
int *allocno_order;

void init_vars() {
    allocno_order = (int*)malloc(max_allocno * sizeof(int));
    if (!allocno_order) {
        exit(1);
    }
}