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
        if ((i & 3) != 0) {  // Skip every 4th iteration (control dependency introduced)
            hptr2[0] += (lptr2[0] + lptr2[stride]) >> 1;
        }
        ++lptr2;
        ++hptr2;
    }
}
