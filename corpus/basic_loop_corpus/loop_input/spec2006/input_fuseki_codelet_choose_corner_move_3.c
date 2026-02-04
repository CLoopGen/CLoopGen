#include <stdint.h>
#include <stdlib.h>

int *table;
int i;
int q;

static int table_data[8];

void init_vars() {
    table = table_data;
    for (i = 0; i < 8; i++) {
        table[i] = (i + 1) * 17;
    }
    q = 1000;
}