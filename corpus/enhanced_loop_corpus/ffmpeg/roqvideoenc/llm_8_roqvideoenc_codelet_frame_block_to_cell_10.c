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
for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++) {
        int x = (top + i) * stride[0] + left + j;
        *block++ = data[0][x];
        x = (top + i) * stride[1] + left + j;
        u += data[1][x] + data[1][x+1] - 1;
        v += data[2][x] + data[2][x+1] - 1;
    }
}
