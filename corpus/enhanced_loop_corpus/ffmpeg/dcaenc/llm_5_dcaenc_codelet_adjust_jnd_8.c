#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t out_cb_unnorm[256];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 256; j++) {
        if (j % 2 == 0) {
            out_cb_unnorm[j] = -2047;
        } else {
            out_cb_unnorm[j] = -2047;
        }
    }
}
