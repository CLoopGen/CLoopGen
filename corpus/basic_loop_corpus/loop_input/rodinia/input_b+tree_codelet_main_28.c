#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct record {
    int value;
} record;

int count;
int i;
record *ans;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // ~64MB of data for sufficient runtime (~0.01 sec)
    count = data_size / sizeof(record);
    ans = calloc(count, sizeof(record));
    if (!ans) {
        exit(1);
    }
}

void loop();

void __attribute__((constructor)) initialize() {
    init_vars();
}