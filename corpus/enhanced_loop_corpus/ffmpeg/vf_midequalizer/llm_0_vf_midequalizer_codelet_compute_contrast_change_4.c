#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *histogram1;
extern float *histogram2;
extern unsigned int *cchange;
extern size_t hsize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 0; i < hsize; i++) {
        j = 0;
        for (; j < hsize; j++) {
            if (histogram2[j] >= histogram1[i]) {
                break;
            }
        }
        cchange[i] = (i + j) / 2;
    }
}
