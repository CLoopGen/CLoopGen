#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

typedef int_fast64_t jpc_fix_big_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    jpc_fix_t* temp_lptr = lptr2;
    jpc_fix_t* temp_hptr = hptr2;
    jpc_fix_t running_correction = 0;
    for (i = 0; i < numcols; ++i) {
        jpc_fix_big_t scaled_val = (jpc_fix_big_t)(temp_hptr[0]);
        jpc_fix_big_t adjusted_factor = (jpc_fix_big_t)((((jpc_fix_t)((2. * (0.443506852043971)) * ((double)(((jpc_fix_t)(1)) << 13))))));
        jpc_fix_t increment = (jpc_fix_t)((adjusted_factor * scaled_val) >> 13);
        running_correction += increment;
        temp_lptr[0] = temp_lptr[0] + running_correction;
        ++temp_lptr;
        ++temp_hptr;
    }
    lptr2 = temp_lptr;
    hptr2 = temp_hptr;
}
