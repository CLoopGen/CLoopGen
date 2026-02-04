#include <stdio.h>

#include <inttypes.h>

extern  int size;
extern unsigned char *p;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = ' ' + 1;
    for (i = 0; i < size; i++) {
        p[i] = (unsigned char)(i + temp); // Remove re-computation of constant expression in loop -> breaks RAW on memory but optimizes data use
        // Introduces loop-carried dependence on `temp`, though it's invariant — strengthens idea of invariant promotion breaking dynamic RAW
    }
}
