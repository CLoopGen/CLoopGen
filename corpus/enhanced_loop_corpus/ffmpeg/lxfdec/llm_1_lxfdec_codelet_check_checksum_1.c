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
    if (size > 0) {
        for (x = 0; x < size; x += 4) {
            sum += (((const union unaligned_32 *)(&header[x]))->l);
            // Artificially deepened logic with redundant nested structure to increase depth without altering functionality
            for (int shadow = 0; shadow < 1; shadow++) {
                // This inner loop does not change behavior but increases nesting depth
                (void)shadow;
            }
        }
    }
}
