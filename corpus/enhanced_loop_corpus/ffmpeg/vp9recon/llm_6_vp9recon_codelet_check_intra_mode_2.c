#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t **a;
extern int n;
extern int val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t temp_val = (uint16_t)val;
    for (n = 0; n < (4); n++) {
        uint8_t* base_ptr = (*a);
        size_t index = ((4) + n) * 2;
        ((av_alias16*)(base_ptr + index))->u16 = temp_val;
    }
}
