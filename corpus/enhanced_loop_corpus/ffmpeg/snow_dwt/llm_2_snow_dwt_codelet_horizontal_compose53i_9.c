#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef short IDWTELEM;

extern IDWTELEM *b;
extern IDWTELEM *temp;
extern  int width2;
extern  int w2;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < width2; x += 2) {
        if (x + 1 < width2) {
            temp[2 * x]       = b[x];
            temp[2 * x + 1]   = b[x + w2];
            temp[2 * (x + 1)] = b[x + 1];
            temp[2 * (x + 1) + 1] = b[x + 1 + w2];
        } else {
            temp[2 * x] = b[x];
            temp[2 * x + 1] = b[x + w2];
        }
    }
}
