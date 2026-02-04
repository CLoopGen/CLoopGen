#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char JSAMPLE;

JSAMPLE *table;
int i;

void init_vars() {
    size_t table_size = 512 * 1024 * 1024; // ~512 MB to ensure loop runtime ~0.01s
    table = (JSAMPLE*)calloc(table_size, sizeof(JSAMPLE));
    if (!table) {
        exit(1);
    }
}