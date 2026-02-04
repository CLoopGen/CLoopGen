#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int datlen;
extern int16_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(datlen * sizeof(int));
    for (int j = 0; j < datlen; j++) {
        indices[j] = datlen - 1 - j; // reverse access pattern
    }
    for (i = 0; i < datlen; i++) {
        int idx = indices[i];
        data[idx] = ((uint8_t *)(data + idx))[0] + 256 * ((uint8_t *)(data + idx))[1];
    }
    free(indices);
}
