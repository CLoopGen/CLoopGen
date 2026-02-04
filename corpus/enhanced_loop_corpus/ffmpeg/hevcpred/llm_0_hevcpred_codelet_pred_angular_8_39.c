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
    for (int i = 0; i <= size; i += 4) {
        for (int j = 0; j < 1; j++) { // Nested single-iteration loop to increase depth
            (((union unaligned_32 *)(&ref_tmp[i]))->l) = (((const union unaligned_32 *)(&top[i - 1]))->l);
        }
    }
}
