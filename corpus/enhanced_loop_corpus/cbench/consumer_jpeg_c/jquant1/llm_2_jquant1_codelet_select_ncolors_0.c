#include <stdio.h>

#include <inttypes.h>

extern int Ncolors[];
extern int nc;
extern int total_colors;
extern int iroot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (i = 0; i < nc; i += 2) {
        Ncolors[i] = iroot;
        total_colors *= iroot;
    }
    // Handle odd-sized nc by processing last element if needed
    if (nc % 2 == 1) {
        Ncolors[nc - 1] = iroot;
        total_colors *= iroot;
    }
}
