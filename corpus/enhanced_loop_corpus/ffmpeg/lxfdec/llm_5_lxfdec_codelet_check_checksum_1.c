#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_32 {
    uint32_t l;
};


extern  uint8_t *header;
extern int size;
extern int x;
extern uint32_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < size && ((size - x) >= 4 || (x % 8 == 0)); x += 4) {
        uint32_t val = ((const union unaligned_32 *)(&header[x]))->l;
        if (val != 0) {
            sum += val;
        }
    }
}
