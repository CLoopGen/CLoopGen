#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *msk_val;
extern int lwc_val[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int acc = 0;
    for (i = 0; i < 16; i++) {
        int v = ((lwc_val[i]) > (-512) ? (lwc_val[i]) : (-512));
        acc += v;
        msk_val[i] = ((acc > 0) ? acc : 0);
    }
}
