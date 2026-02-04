#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t out_cb_unnorm[256];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 64; j++) {
        out_cb_unnorm[j * 4 + 0] = -2047;
        out_cb_unnorm[j * 4 + 1] = -2047;
        out_cb_unnorm[j * 4 + 2] = -2047;
        out_cb_unnorm[j * 4 + 3] = -2047;
    }
}
