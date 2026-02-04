#include <stdio.h>

#include <inttypes.h>

extern int Ncolors[];
extern int nc;
extern int total_colors;
extern int iroot;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int j = 0; j < nc; j++) {
    for (i = 0; i <= j; i++) {
        Ncolors[i] = iroot;
        total_colors *= iroot;
    }
}
}
