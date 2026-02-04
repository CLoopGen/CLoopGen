#include <stdint.h>
#include <stdlib.h>

int *table;
int in;
int out;

static int *table_storage;

void init_vars() {
    size_t data_size = 128 * 1024 * 1024;
    size_t num_elements = data_size / sizeof(int);
    
    table_storage = (int*)calloc(num_elements, sizeof(int));
    table = table_storage + num_elements / 2;

    in = 0;
    out = 0;
}