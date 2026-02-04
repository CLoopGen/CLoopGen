#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern int i;
extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FFTSample *local_tab = tab;
    int local_m = m;
    for (i = 1; i < local_m / 4; i++) {
        local_tab[local_m / 2 - i] = local_tab[i];
        local_tab[i] = local_tab[local_m / 2 - i]; // Introduces WAW and WAR dependency, creates loop-carried dependence
    }
}
