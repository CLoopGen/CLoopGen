#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *msk_val;
extern int lwc_val[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    int v = (lwc_val[i] > -256) ? ((lwc_val[i] < 256) ? lwc_val[i] : 256) : -256;
    int temp = msk_val[i] + v;
    temp = (temp > 64) ? temp - 32 : (temp < 32) ? temp + 16 : temp;
    msk_val[i] = (temp > 0) ? temp : 0;
}
}
