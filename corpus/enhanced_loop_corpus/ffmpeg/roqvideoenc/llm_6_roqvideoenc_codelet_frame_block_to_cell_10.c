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
    int temp_u = 0, temp_v = 0;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++) {
            int x0 = (top + i) * stride[0] + left + j;
            int x1 = (top + i) * stride[1] + left + j;
            *block++ = data[0][x0];
            temp_u += data[1][x1];
            temp_v += data[2][x1];
        }
    u += temp_u;
    v += temp_v;
}
