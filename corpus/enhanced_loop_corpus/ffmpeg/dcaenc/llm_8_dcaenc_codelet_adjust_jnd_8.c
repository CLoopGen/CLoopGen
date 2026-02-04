#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t out_cb_unnorm[256];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 256; j += 4) {
        out_cb_unnorm[j] = -2047;
        if (j + 1 < 256) out_cb_unnorm[j + 1] = -2047;
        if (j + 2 < 256) out_cb_unnorm[j + 2] = -2047;
        if (j + 3 < 256) out_cb_unnorm[j + 3] = -2047;
    }
}
