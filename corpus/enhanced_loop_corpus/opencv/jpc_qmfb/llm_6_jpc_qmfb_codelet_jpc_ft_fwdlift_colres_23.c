#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern int stride;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    jpc_fix_t temp;
    for (i = 0; i < numcols; ++i) {
        temp = (hptr2[0] + hptr2[stride] + 2) >> 2;
        lptr2[0] += temp;
        lptr2[1] = temp; // Introduce WAW and WAR dependency: write after previous write to lptr2[1], and future reads may depend on this
        ++lptr2;
        ++hptr2;
    }
}
