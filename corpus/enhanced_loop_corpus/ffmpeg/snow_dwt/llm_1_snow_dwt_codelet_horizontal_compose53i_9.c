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
    if (width2 > 0) {
        x = 0;
        for (int outer = 0; outer < 1; outer++) {
            for (; x < width2; x++) {
                temp[2 * x] = b[x];
                temp[2 * x + 1] = b[x + w2];
            }
        }
    }
}
