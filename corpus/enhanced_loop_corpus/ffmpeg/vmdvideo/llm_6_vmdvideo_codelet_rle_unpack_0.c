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
    uint16_t temp_run_val = run_val;
    for (i = 0; i < l; i++) {
        ((((union unaligned_16 *)(pd))->l) = (temp_run_val));
        temp_run_val += run_val; // Introduce WAW and RAW dependency: each iteration depends on previous write to temp_run_val
        pd += 2;
    }
}
