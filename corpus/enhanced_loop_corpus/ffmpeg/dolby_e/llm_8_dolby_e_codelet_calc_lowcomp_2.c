#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *msk_val;
extern int lwc_val[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    int v1 = (lwc_val[i] > -512) ? lwc_val[i] : -512;
    int v2 = (lwc_val[i+1] > -512) ? lwc_val[i+1] : -512;
    msk_val[i] = (msk_val[i] + v1 > 0) ? msk_val[i] + v1 : 0;
    msk_val[i+1] = (msk_val[i+1] + v2 > 0) ? msk_val[i+1] + v2 : 0;
}
}
