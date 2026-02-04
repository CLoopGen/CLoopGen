#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *t;
extern int w;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *local_t = t;
    int local_w = w;
    int local_h = h;
    int size = local_w * local_h;
    for (i = 0; i < size; i++) {
        int temp = local_t[i];
        temp = (temp + ((1 << 8) >> 1)) >> 8;
        local_t[i] = temp;
    }
}
