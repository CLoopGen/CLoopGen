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
    int i, j;
    for (i = 0; i < width2; i++) {
        for (j = 0; j < 2; j++) {
            if (j == 0) {
                temp[i] = b[2 * i];
            } else {
                temp[i + w2] = b[2 * i + 1];
            }
        }
    }
}
