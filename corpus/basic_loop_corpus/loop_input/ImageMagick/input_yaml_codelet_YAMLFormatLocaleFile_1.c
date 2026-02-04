#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *value;
char *p;
size_t length;

static char data[1 << 20]; // 1MB of input data

void init_vars() {
    // Initialize data with mixed content to trigger various loop paths
    for (int i = 0; i < (1 << 20) - 100; i++) {
        switch (i % 16) {
            case 0: data[i] = '"'; break;
            case 1: data[i] = '\b'; break;
            case 2: data[i] = '\f'; break;
            case 3: data[i] = '\n'; break;
            case 4: data[i] = '\r'; break;
            case 5: data[i] = '\t'; break;
            case 6: data[i] = '\\'; break;
            case 7: data[i] = 0x01; break; // control char
            case 8: data[i] = 0x1F; break; // control char
            default: data[i] = 'a' + (i % 26); break;
        }
    }
    // Ensure null termination
    data[(1 << 20) - 1] = '\0';

    // Initialize external variables
    value = data;
    p = value;
    length = 1000;
}