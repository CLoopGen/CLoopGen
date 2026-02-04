#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int_fast32_t jpc_fix_t;

extern int numcols;
extern jpc_fix_t *lptr2;
extern jpc_fix_t *hptr2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (numcols <= 0) return;
    hptr2[0] += lptr2[0];
    for (i = 1; i < numcols; ++i) {
        hptr2[i] += lptr2[i - 1]; // Introduces WAR dependency: write to hptr2[i] after read of lptr2[i-1]
    }
}
