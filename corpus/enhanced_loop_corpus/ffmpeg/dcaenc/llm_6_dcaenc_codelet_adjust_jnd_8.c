#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t out_cb_unnorm[256];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp = -2047;
    for (j = 0; j < 256; j++) {
        out_cb_unnorm[j] = temp;
    }
}
