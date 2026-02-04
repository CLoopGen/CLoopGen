#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int i;
extern int size;
extern uint8_t *top;
extern uint32_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc((size / 4) * sizeof(int));
    int j;
    for (j = 0; j < size / 4; j++) {
        indices[j] = j * 4;
    }
    for (j = 0; j < size / 4; j++) {
        int idx = indices[j];
        (((union unaligned_32 *)(top + idx))->l) = pix;
    }
    free(indices);
}
