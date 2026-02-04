#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *v;
extern  int *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i++) {
        int temp1 = src[63 - 2 * i];
        int temp2 = src[63 - 2 * i - 1];
        v[i] = (int)(16U + temp1) >> 5;
        v[63 - i] = (int)(16U - temp2) >> 5;
    }
}
