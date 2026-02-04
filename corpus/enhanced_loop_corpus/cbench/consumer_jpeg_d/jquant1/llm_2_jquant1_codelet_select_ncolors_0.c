#include <stdio.h>

#include <inttypes.h>

extern int Ncolors[];
extern int nc;
extern int total_colors;
extern int iroot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < nc; i += 2) {
        if (i < nc) {
            Ncolors[i] = iroot;
            total_colors *= iroot;
        }
    }
}
