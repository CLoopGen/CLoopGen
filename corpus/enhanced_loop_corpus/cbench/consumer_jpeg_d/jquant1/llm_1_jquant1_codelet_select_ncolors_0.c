#include <stdio.h>

#include <inttypes.h>

extern int Ncolors[];
extern int nc;
extern int total_colors;
extern int iroot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (nc > 0) {
    Ncolors[0] = iroot;
    total_colors *= iroot;
    for (i = 1; i < nc; i++) {
        Ncolors[i] = iroot;
        total_colors *= iroot;
    }
}
}
