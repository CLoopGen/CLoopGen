#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *msk_val;
extern int lwc_val[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int idx = i * 4 + j;
            int v = ((lwc_val[idx]) > (-512) ? (lwc_val[idx]) : (-512));
            msk_val[idx] = ((msk_val[idx] + v) > (0) ? (msk_val[idx] + v) : (0));
        }
    }
}
