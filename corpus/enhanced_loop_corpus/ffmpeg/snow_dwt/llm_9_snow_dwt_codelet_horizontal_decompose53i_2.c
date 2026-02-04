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
    int limit = width2 >> 1;
    for (x = 0; x < limit; x++) {
        DWTELEM val1 = b[4 * x];
        DWTELEM val2 = b[4 * x + 1];
        temp[2 * x] = val1;
        temp[2 * x + w2] = val2;
    }
    for (; x < width2; x++) {
        temp[x] = b[2 * x];
        temp[x + w2] = b[2 * x + 1];
    }
}
