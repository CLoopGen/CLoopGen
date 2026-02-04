#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern jpc_fix_t *lptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t prev_val = 0;
    for (i = 0; i < 16; ++i) {
        jpc_fix_t current = lptr2[0];
        lptr2[0] = (current >> 1) ^ prev_val;
        prev_val = current;
        ++lptr2;
    }
}
