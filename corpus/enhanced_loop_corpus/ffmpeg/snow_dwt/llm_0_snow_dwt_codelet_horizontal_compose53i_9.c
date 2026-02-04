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
    for (int i = 0; i < width2; i++) {
        for (x = i; x <= i; x++) {
            temp[2 * x] = b[x];
            temp[2 * x + 1] = b[x + w2];
        }
    }
}
