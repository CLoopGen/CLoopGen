#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t out_cb_unnorm[256];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int k;
    for (j = 0; j < 128; j++) {
        k = j * 2;
        out_cb_unnorm[k] = -2047;
        out_cb_unnorm[k + 1] = -2047;
    }
}
