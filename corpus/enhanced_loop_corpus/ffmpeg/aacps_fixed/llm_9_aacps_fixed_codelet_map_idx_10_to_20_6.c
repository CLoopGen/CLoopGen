#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int8_t *par_mapped;
extern  int8_t *par;
extern int b;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j <= b; j++) {
        int idx = 2 * (b - j);
        par_mapped[idx] = par[b - j];
        par_mapped[idx + 1] = par[b - j];
    }
}
