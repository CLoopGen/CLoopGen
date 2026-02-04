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
for (i = 0; i < hsize; i++) {
    int j;
    size_t idx = i * 2 % hsize;
    for (j = 0; j < hsize; j++) {
        size_t access_idx = (j * 3) % hsize;
        if (histogram2[access_idx] >= histogram1[idx])
            break;
    }
    cchange[idx] = (idx + j) / 2;
}
}
