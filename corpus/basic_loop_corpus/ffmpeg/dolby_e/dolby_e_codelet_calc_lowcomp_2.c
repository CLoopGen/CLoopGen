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
    int v = ((lwc_val[i]) > (-512) ? (lwc_val[i]) : (-512));
    msk_val[i] = ((msk_val[i] + v) > (0) ? (msk_val[i] + v) : (0));
}

}
