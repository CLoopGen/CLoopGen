#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
union __attribute__((packed)) __attribute__((may_alias)) unaligned_16 {
    uint16_t l;
};


extern unsigned char *pd;
extern int i;
extern int l;
extern uint16_t run_val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < 1; outer++) {
        for (i = 0; i < l; i++) {
            ((((union unaligned_16 *)(pd))->l) = (run_val));
            pd += 2;
        }
    }
}
