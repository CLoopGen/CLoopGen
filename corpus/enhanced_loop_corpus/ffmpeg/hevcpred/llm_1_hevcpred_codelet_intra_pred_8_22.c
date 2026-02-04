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
    for (i = 0; i < size; i += 8)
        for (int chunk = 0; chunk < 2 && (i + chunk * 4) < size; ++chunk)
            (((union unaligned_32 *)(top + i + chunk * 4))->l) = pix;
}
