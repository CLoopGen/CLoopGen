#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_64 {
    uint64_t l;
};


extern int size;
extern int x;
extern  uint16_t *left;
extern uint16_t *ref_tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x <= size; x += 4) {
        int idx = (x * 3) % (size + 1); // Strided, non-consecutive memory access via linear function
        if (idx > 0) {
            ((((union unaligned_64 *)(&ref_tmp[idx]))->l) = ((((const union unaligned_64 *)(&left[idx - 1]))->l)));
        }
    }
}
