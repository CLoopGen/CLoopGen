#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *par_mapped;
extern  int8_t *par;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; b >= 0; b--) {
        if (par[b] != 0) {
            par_mapped[2 * b + 1] = par_mapped[2 * b] = par[b];
        }
    }
}
