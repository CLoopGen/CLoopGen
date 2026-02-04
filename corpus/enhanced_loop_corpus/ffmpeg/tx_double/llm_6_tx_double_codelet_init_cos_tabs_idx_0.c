#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    FFTSample *local_tab = tab;
    int limit = m / 4;
    int mid = m / 2;
    for (int i = 1; i < limit; i++) {
        local_tab[mid - i] = local_tab[i];
        local_tab[i + 1] += local_tab[i]; // Introduce WAW and RAW dependency: each iteration depends on previous write
    }
}
