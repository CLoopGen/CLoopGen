#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection shadow[400];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i, j;
    for (i = 1; i < 19; i++)
        for (j = 1; j < 19; j++) {
            k = i * 20 + j;
            active[k] = shadow[k];
        }
}
