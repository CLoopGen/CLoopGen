#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int value;
extern int rate;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    int *val_ptr = &value;
    for (int c = (rate + 128) >> 8; c--;) {
        *val_ptr += (65536 - *val_ptr) >> 8;
    }
}
