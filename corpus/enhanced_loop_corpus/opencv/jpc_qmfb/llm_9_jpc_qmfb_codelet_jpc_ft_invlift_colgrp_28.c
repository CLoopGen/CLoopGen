#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; ++i) {
    jpc_fix_t temp_h = hptr2[0];
    lptr2[0] -= (temp_h + 1) >> 1;
    lptr2[1] -= (temp_h + 1) >> 1;
    lptr2[2] -= (temp_h + 1) >> 1;
    lptr2[3] -= (temp_h + 1) >> 1;
    lptr2 += 4;
    ++hptr2;
}
}
