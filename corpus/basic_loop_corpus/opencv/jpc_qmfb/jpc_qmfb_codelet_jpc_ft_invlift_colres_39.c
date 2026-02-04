#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < numcols; ++i) {
    lptr2[0] >>= 1;
    ++lptr2;
}

}
