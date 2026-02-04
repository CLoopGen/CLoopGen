#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int DWTELEM;

extern DWTELEM *b;
extern DWTELEM *temp;
extern  int width2;
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed iteration and offset indexing
    for (x = width2 - 1; x >= 0; x--) {
        int idx = width2 - 1 - x;  // reverse index
        temp[idx] = b[2 * x];
        temp[idx + w2] = b[2 * x + 1];
    }
}
