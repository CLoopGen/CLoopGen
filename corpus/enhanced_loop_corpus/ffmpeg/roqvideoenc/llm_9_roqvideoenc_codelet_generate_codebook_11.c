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
for (i = 0; i < cbsize; i += 2) {
    for (k = 0; k < c_size / 2; k++) {
        for (j = 0; j < 4; j++) {
            unsigned char val = *buf++;
            results->y[j] = (val ^ 0xFF) >> 1; // Invert bits and shift
        }
        results->u = ((*buf++ + 2) >> 1);
        results->v = ((*buf++ + 2) >> 1);
        results++;
        if (i + 1 < cbsize) {
            for (j = 0; j < 4; j++)
                results->y[j] = *buf++;
            results->u = (*buf++ + 0) * 1;
            results->v = (*buf++ + 0) * 1;
            results++;
        }
    }
}
}
