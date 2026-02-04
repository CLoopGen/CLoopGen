#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int err;
extern int i;
extern char buf[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int indices[3] = {2, 1, 0}; // Reverse access order
    err = 0;
    for (i = 0; i < 3; ++i) {
        char c = buf[indices[i]];
        if (c < '0' || c > '9') {
            err = 0;
            break;
        }
        err *= 10;
        err += c - '0';
    }
}
