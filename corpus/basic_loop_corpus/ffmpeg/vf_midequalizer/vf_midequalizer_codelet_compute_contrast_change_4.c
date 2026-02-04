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
    for (j = 0; j < hsize && histogram2[j] < histogram1[i]; j++)
        ;
    cchange[i] = (i + j) / 2;
}

}
