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
        for (int j = 0; j < 2; j++) {
            int idx = 2 * i + j;
            v[idx] = (int)(16U + src[63 - 2 * idx]) >> 5;
            v[63 - idx] = (int)(16U - src[63 - 2 * idx - 1]) >> 5;
        }
    }
}
