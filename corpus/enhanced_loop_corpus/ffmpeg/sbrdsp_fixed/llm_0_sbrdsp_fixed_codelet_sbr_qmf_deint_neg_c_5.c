#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *v;
extern  int *src;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 32; i += 2) {
        v[i] = (int)(16U + src[63 - 2 * i]) >> 5;
        v[63 - i] = (int)(16U - src[63 - 2 * i - 1]) >> 5;
        if (i + 1 < 32) {
            v[i + 1] = (int)(16U + src[63 - 2 * (i + 1)]) >> 5;
            v[63 - (i + 1)] = (int)(16U - src[63 - 2 * (i + 1) - 1]) >> 5;
        }
    }
}
