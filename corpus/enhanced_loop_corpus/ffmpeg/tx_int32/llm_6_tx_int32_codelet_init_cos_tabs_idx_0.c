#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FFTSample *local_tab = tab;
    int32_t bound = m / 4;
    int32_t mid = m / 2;
    for (int i = 1; i < bound; i++) {
        local_tab[mid - i] = local_tab[i];
        local_tab[i] = local_tab[mid - i]; // Introduces WAW and WAR dependency; creates loop-carried dependence via reuse of written values
    }
}
