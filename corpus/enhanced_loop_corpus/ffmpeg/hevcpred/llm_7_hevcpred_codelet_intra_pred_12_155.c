#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *left;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_pix[2] = {pix, pix ^ 0x8000800080008000ULL};
    int idx;
    for (i = 0; i < (size); i += 4) {
        idx = (i >> 3) & 1; // Stride-based index into local_pix
        (((union unaligned_64 *)(left + i))->l) = local_pix[idx]; // Remove loop-carried dep by using independent data
    }
}
