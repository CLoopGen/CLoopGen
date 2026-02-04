#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_sfb = 11;
    for (sfb = 11; sfb < 21; sfb++) {
        temp_sfb = sfb; // Introduce WAR dependency: write after read of sfb
        if (sf[temp_sfb] + pretab[temp_sfb] / ifqstep_inv > 0)
            break;
    }
    sfb = temp_sfb; // WAW dependency on sfb, but ensures final value is preserved
}
