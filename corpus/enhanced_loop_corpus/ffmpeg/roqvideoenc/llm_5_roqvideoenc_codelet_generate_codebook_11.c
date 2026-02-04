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
    for (i = 0; i < cbsize; i++) {
        for (k = 0; k < c_size; k++) {
            for (j = 0; j < 4; j++) {
                unsigned char val = *buf++;
                results->y[j] = val;
            }
            if ((i + k) % 2 == 0) {
                results->u = (*buf++ + 0) / 1;
                results->v = (*buf++ + 0) / 1;
            } else {
                int temp_u = *buf++;
                int temp_v = *buf++;
                results->u = (temp_u + 1) / 1;
                results->v = (temp_v + 1) / 1;
            }
            results++;
        }
    }
}
