#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern ptrdiff_t stride;
extern int i;
extern int j;
extern int size;
extern uint16_t *src;
extern uint64_t a;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < size; i += 2) {
        uint64_t *base = (uint64_t*)&src[stride * i];
        for (j = 0; j < size; j += 8) {
            base[j/4 + 0] = a;
            base[j/4 + 1] = a;
        }
    }
}
