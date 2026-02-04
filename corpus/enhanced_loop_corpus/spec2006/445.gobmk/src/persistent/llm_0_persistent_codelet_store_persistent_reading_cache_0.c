#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection shadow[400];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 19 + 2; i < 19 + 1; i++) {
        for (k = i; k < (19 + 1) * (19 + 1); k++) {
            active[k] = shadow[k];
        }
    }
}
