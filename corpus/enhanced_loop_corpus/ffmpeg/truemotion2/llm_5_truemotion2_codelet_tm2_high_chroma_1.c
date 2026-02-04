#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *data;
extern int stride;
extern int *last;
extern unsigned int *CD;
extern int *deltas;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 2; j++) {
        for (i = 0; i < 2; i++) {
            if (i == 0 || j == 0) {
                CD[j] += deltas[i + j * 2];
            }
            last[i] += CD[j];
            data[i] = last[i];
        }
        if (j % 2 == 0) {
            data += stride;
        } else {
            data += stride + 1;
        }
    }
}
