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
    uint16_t *ptr = (uint16_t*)pd;
    for (i = 0; i < l; i++) {
        ptr[i] = run_val;
    }
}
