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
    for (i = 0; i < 16; ++i) {
        ++lptr2;
        ++hptr2;
        if (i >= 4) {
            lptr2[-1] -= (hptr2[-1] + 1) >> 1;
        }
    }
}
