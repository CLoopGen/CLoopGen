#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int err;
extern int i;
extern char buf[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (process every 2nd element, starting at index 0)
    err = 0;
    for (i = 0; i < 3; i += 2) {
        if (buf[i] < '0' || buf[i] > '9') {
            err = 0;
            break;
        }
        err *= 10;
        err += buf[i] - '0';
    }
    // Handle remaining elements if needed, but limit to original range
    for (; i < 3; ++i) {
        if (buf[i] < '0' || buf[i] > '9') {
            err = 0;
            break;
        }
        err *= 10;
        err += buf[i] - '0';
    }
}
