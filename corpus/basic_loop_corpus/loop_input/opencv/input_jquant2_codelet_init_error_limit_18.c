#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int *table;
int in;
int out;

static int internal_table_buffer[1048576]; // 4MB buffer to allow safe access for ±index

void init_vars() {
    table = internal_table_buffer + 524288; // Center the accessible range to allow negative indexing
    in = 0;
    out = 0;
}