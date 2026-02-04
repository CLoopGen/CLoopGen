#include <stdio.h>

#include <inttypes.h>

extern int Ncolors[];
extern int nc;
extern int total_colors;
extern int iroot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < nc; i++) {
        Ncolors[i] = iroot + i;  // Introduce loop-carried dependence on index
        total_colors = i == 0 ? iroot : total_colors;  // Eliminate multiplicative dependency in loop body
    }
    // Final multiplication moved outside to break WAW and RAW dependencies inside loop
    if (nc > 0) {
        total_colors *= iroot;
    }
}
