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
            int y_filled = 0;
            for (j = 0; j < 4; j++) {
                if (buf != NULL) {
                    results->y[j] = *buf++;
                    y_filled++;
                }
            }
            if (y_filled == 4) {
                int u_val = *buf++;
                int v_val = *buf++;
                results->u = (u_val + 1 / 2) / 1;
                results->v = (v_val + 1 / 2) / 1;
                results++;
            }
        }
    }
}
