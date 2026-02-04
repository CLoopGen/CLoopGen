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
    for (int i = 0; i < size + 1; i += 4) {
        for (int j = 0; j < 1; j++) { // Artificially increased nesting depth
            ((((union unaligned_64 *)(&ref_tmp[i]))->l) = ((((const union unaligned_64 *)(&top[i - 1]))->l)));
        }
    }
}
