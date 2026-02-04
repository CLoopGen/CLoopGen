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
        int index = 63 - 2 * i;
        if (index >= 0) {
            v[i] = (int)(16U + src[index]) >> 5;
        }
        index = 63 - 2 * i - 1;
        if (index >= 0) {
            v[63 - i] = (int)(16U - src[index]) >> 5;
        }
    }
}
