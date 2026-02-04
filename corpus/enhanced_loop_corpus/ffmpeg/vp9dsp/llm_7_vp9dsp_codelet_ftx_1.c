#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *buf;
extern int sz;
extern int bit_depth;
extern double ind[1024];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp;
    for (n = 0; n < sz * sz; n++) {
        if (bit_depth == 8) {
            temp = buf[n];
        } else {
            temp = ((int32_t *)buf)[n];
        }
        ind[n] = temp;
    }
}
