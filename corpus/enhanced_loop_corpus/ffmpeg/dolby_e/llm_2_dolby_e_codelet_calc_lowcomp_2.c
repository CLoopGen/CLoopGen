#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *msk_val;
extern int lwc_val[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided access with stride of 2 (forward traversal)
    for (i = 0; i < 16; i += 2) {
        int v = ((lwc_val[i]) > (-512) ? (lwc_val[i]) : (-512));
        msk_val[i] = ((msk_val[i] + v) > (0) ? (msk_val[i] + v) : (0));
        
        // Handle next element if within bounds
        if (i + 1 < 16) {
            int v_next = ((lwc_val[i + 1]) > (-512) ? (lwc_val[i + 1]) : (-512));
            msk_val[i + 1] = ((msk_val[i + 1] + v_next) > (0) ? (msk_val[i + 1] + v_next) : (0));
        }
    }
}
