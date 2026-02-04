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
    int count = 0;
    for (int temp_i = 0; temp_i < size; temp_i += 4)
        indices[count++] = temp_i;

    for (int j = 0; j < count; j++) {
        int idx = indices[j];
        ((((union unaligned_32 *)(top + idx))->l) = (pix));
    }
    free(indices);
}
