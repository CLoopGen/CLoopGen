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
        int temp_cd = CD[j];
        for (i = 0; i < 2; i++) {
            temp_cd += deltas[i + j * 2];
            last[i] += temp_cd;
            data[i] = last[i];
        }
        CD[j] = temp_cd;
        data += stride;
    }
}
