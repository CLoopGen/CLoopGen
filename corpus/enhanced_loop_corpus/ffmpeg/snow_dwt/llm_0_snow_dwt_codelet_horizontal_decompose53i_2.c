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
    int y;
    for (y = 0; y < 2; y++) {
        for (x = 0; x < width2; x++) {
            if (y == 0) {
                temp[x] = b[2 * x];
            } else {
                temp[x + w2] = b[2 * x + 1];
            }
        }
    }
}
