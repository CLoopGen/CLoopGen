#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern jpc_fix_t *lptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int indices[16] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0};
    for (i = 0; i < 16; ++i) {
        lptr2[indices[i]] <<= 1;  // Indirect access via index array (reverse order)
    }
}
