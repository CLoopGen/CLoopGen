#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct roq_cell {
    unsigned char y[4];
    unsigned char u;
    unsigned char v;
} roq_cell;

extern roq_cell *results;
extern int cbsize;
extern int i;
extern int j;
extern int k;
extern int c_size;
extern int *buf;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < cbsize; i++)
    for (j = 0; j < 4; j++)
        for (k = 0; k < c_size; k++) {
            results->y[j] = *buf++;
            if (j == 3) {
                results->u = (*buf++ + 1 / 2) / 1;
                results->v = (*buf++ + 1 / 2) / 1;
                results++;
            }
        }
}
