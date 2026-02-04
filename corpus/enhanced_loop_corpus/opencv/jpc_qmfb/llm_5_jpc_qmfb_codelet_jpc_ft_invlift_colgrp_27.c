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
    for (i = 0; i < 16; ++i) {
        if (hptr2[0] >= 0) {  // Only perform update when current hptr2 value is non-negative
            lptr2[0] -= (hptr2[0] + hptr2[stride] + 2) >> 2;
        }
        ++lptr2;
        ++hptr2;
    }
}
