#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int size;
extern int x;
extern  uint16_t *top;
extern uint16_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x <= size; x += 4) {
        if (x < size - 2) {
            (((union unaligned_64 *)(&ref_tmp[x]))->l) = ((((const union unaligned_64 *)(&top[x - 1]))->l));
        } else {
            ref_tmp[x] = top[x - 1];
            if (x + 1 <= size) ref_tmp[x + 1] = top[x];
            if (x + 2 <= size) ref_tmp[x + 2] = top[x + 1];
            if (x + 3 <= size) ref_tmp[x + 3] = top[x + 2];
        }
    }
}
