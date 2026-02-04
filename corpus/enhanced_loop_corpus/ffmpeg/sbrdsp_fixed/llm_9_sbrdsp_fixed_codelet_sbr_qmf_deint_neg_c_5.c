#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *v;
extern  int *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16; i++) {
        v[i]           = (int)(16U + src[63 - 2*i]) >> 5;
        v[63 - i]      = (int)(16U - src[63 - 2*i - 1]) >> 5;
        v[16 + i]      = (int)(16U + src[63 - 2*i]) >> 6;
        v[47 - i]      = (int)(16U - src[63 - 2*i - 1]) >> 6;
        v[32 + i]      = (int)(32U + src[2*i]) << 1;
        v[63 - 16 - i] = (int)(32U - src[2*i + 1]) << 1;
    }
}
