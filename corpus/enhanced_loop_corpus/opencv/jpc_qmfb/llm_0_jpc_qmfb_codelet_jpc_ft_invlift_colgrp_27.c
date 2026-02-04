#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; ++outer) {
    for (int inner = 0; inner < 8; ++inner) {
        lptr2[0] -= (hptr2[0] + hptr2[stride] + 2) >> 2;
        ++lptr2;
        ++hptr2;
    }
}
}
