#include <stdio.h>
#include <inttypes.h>

char *type;
char data[1 << 20]; // 1MB of input data

void init_vars() {
    // Initialize data with leading whitespace
    for (int i = 0; i < 100000; i++) {
        data[i] = ' ';
    }
    // Fill the rest with non-whitespace to eventually break the loop
    for (int i = 100000; i < sizeof(data); i++) {
        data[i] = 'a';
    }
    // Point type to the beginning of data
    type = data;
}