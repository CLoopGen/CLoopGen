#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int size;
extern int x;
extern  uint8_t *left;
extern uint8_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int indices[] = {0, 4, 8, 12, 16, 20}; // Example small set of indices for strided indirect access
    int num_indices = 6;
    for (int i = 0; i < num_indices; ++i) {
        int x = indices[i];
        if (x > 0 && x <= size) {
            ((((union unaligned_32 *)(&ref_tmp[x]))->l) = ((((const union unaligned_32 *)(&left[x - 1]))->l)));
        }
    }
}
