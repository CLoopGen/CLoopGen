#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern int size;
extern int x;
extern  uint8_t *top;
extern uint8_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x <= size; x += 8)
        for (int inner = 0; inner < 2; ++inner)
            if (x + 4 * inner <= size)
                ((((union unaligned_32 *)(&ref_tmp[x + 4 * inner]))->l) = ((((const union unaligned_32 *)(&top[x + 4 * inner - 1]))->l)));
}
