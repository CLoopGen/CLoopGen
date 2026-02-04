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
    for (i = 0; i < size; ++i) {
        for (int j = 0; j < 2; ++j) {
            int index = i * 2 + j * 2;
            if (index < 2 * size)
                ((((union unaligned_64 *)(left + index))->l) = (pix));
        }
    }
}
