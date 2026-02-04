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
    int indices[4];
    for (x = 0; x <= size; x += 4) {
        indices[0] = x;
        indices[1] = x + 1;
        indices[2] = x + 2;
        indices[3] = x + 3;
        ((((union unaligned_64 *)(&ref_tmp[indices[0]]))->l) = ((((const union unaligned_64 *)(&top[indices[0] - 1]))->l)));
    }
}
