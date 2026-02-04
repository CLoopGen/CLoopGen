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
    if (size >= 0) {
        for (int outer = 0; outer <= size; outer += 16) { // Outer loop with larger step
            int limit = (outer + 15 < size) ? outer + 15 : size;
            for (int inner = outer; inner <= limit; inner += 4) { // Inner loop handling block of 4-byte copies
                (((union unaligned_32 *)(&ref_tmp[inner]))->l) = (((const union unaligned_32 *)(&top[inner - 1]))->l);
            }
        }
    }
}
