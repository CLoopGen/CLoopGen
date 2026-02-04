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
extern uint64_t pix;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (size > 0) {
        i = 0;
        for (; i < (size); i += 4) {
            ((((union unaligned_64 *)(top + i))->l) = (pix));
            i += 4;
            if (i >= size) break;
            ((((union unaligned_64 *)(top + i))->l) = (pix));
        }
    }
}
