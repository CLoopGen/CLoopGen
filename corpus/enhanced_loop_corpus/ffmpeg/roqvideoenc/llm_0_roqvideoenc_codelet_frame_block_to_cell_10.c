#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *block;
extern uint8_t * *data;
extern int top;
extern int left;
extern  int *stride;
extern int i;
extern int j;
extern int u;
extern int v;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 2; i++) {
        int x1, x2;
        x1 = (top + i) * stride[0] + left;
        x2 = (top + i) * stride[1] + left;
        for (j = 0; j < 2; j++) {
            *block++ = data[0][x1 + j];
            u += data[1][x2 + j];
            v += data[2][x2 + j];
        }
    }
}
