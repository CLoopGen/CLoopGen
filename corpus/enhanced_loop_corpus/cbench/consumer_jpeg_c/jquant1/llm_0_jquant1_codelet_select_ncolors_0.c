#include <stdio.h>

#include <inttypes.h>

extern int Ncolors[];
extern int nc;
extern int total_colors;
extern int iroot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j;
for (i = 0; i < nc; i++) {
    Ncolors[i] = iroot;
    for (j = 0; j < iroot; j++) {
        total_colors *= iroot;
    }
}
}
