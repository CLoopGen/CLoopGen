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
    unsigned int *local_cchange = (unsigned int*)malloc(hsize * sizeof(unsigned int));
    if (!local_cchange) return;
    for (i = 0; i < hsize; i++) {
        int j = 0;
        float val1 = histogram1[i];
        float val2;
        for (j = 0; j < hsize; j++) {
            val2 = histogram2[j];
            if (val2 >= val1) break;
        }
        local_cchange[i] = (i + j) / 2;
    }
    for (i = 0; i < hsize; i++) {
        cchange[i] = local_cchange[i];
    }
    free(local_cchange);
}
