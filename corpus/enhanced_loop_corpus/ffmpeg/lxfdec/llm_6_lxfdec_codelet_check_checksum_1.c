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
    uint32_t temp_sum = 0;
    for (x = 0; x < size; x += 4) {
        temp_sum += (((const union unaligned_32 *)(&header[x]))->l);
    }
    sum += temp_sum;
}
