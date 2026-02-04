#include <stdio.h>

#include <inttypes.h>

extern int Ncolors[];
extern int nc;
extern int total_colors;
extern int iroot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 1;
    for (i = 0; i < nc; i++) {
        Ncolors[i] = iroot;
        temp *= iroot;
    }
    total_colors *= temp;
}
