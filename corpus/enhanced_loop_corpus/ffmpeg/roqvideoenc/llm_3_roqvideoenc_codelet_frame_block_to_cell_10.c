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
    // Variant 2: Strided access with reversed loop order to simulate column-major traversal
    int x0, x1;
    // Swap loop order: iterate over j (column) first, then i (row)
    for (j = 0; j < 2; j++)
        for (i = 0; i < 2; i++) {
            x0 = (top + i) * stride[0] + left + j;
            *block++ = data[0][x0];
            x1 = (top + i) * stride[1] + left + j;
            u += data[1][x1];
            v += data[2][x1];
        }
}
