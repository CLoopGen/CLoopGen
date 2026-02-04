#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern jpc_fix_t *lptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 4; ++outer) {
    for (i = 0; i < 4; ++i) {
        lptr2[0] >>= 1;
        ++lptr2;
    }
}
}
