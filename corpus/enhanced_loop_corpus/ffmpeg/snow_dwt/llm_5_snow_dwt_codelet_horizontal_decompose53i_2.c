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
    for (x = 0; x < width2; x++) {
        temp[x] = b[2 * x];
        if (x < w2) {
            temp[x + w2] = b[2 * x + 1];
        }
    }
}
