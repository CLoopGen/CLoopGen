#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int i;
extern int size;
extern uint16_t *top;
extern int top_right_size;
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_pix[2] = {pix, pix ^ 0xFFFFFFFFFFFFFFFFULL};
    for (i = 0; i < (size - top_right_size); i += 8) { // Double the step to reduce iterations and decouple dependencies
        if (i + 0 < (size - top_right_size))
            (((union unaligned_64 *)(top + size + top_right_size + i))->l) = local_pix[0];
        if (i + 4 < (size - top_right_size))
            (((union unaligned_64 *)(top + size + top_right_size + i + 4))->l) = local_pix[1]; // Remove loop-carried dependency by using independent values
    }
}
