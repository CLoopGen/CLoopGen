#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

int *reg_last_set_table_tick;
int label_tick;
unsigned int regno;
unsigned int endregno;
unsigned int r;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    reg_last_set_table_tick = (int*)calloc(data_size, sizeof(int));
    if (!reg_last_set_table_tick) {
        exit(1);
    }
    label_tick = 42;
    regno = 0;
    endregno = data_size;
}