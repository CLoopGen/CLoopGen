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
    int local_last[2];
    local_last[0] = last[0];
    local_last[1] = last[1];

    for (j = 0; j < 2; j++) {
        int cd_val = CD[j];
        for (i = 0; i < 2; i++) {
            cd_val += deltas[i + j * 2];
            local_last[i] += cd_val;
        }
        CD[j] = cd_val;
    }

    for (i = 0; i < 2; i++) {
        last[i] = local_last[i];
        data[i] = last[i];
    }
    data += stride;
    data += stride;
}
