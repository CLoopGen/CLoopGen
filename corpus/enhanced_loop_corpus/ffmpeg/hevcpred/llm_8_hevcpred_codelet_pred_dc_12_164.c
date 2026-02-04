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
        uint64_t local_a = a;
        for (j = 0; j < size; j += 8) {
            ((union unaligned_64 *)(&src[j + stride * i]))->l = local_a;
            if (j + 4 < size) {
                ((union unaligned_64 *)(&src[j + 4 + stride * i]))->l = local_a;
            }
        }
    }
}
