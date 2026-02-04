#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection shadow[400];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = (19 + 2); i < (19 + 1) * (19 + 1); i++) {
        active[i] = shadow[i];
        shadow[i] = shadow[i]; // Introduce WAW dependency: write-after-write on shadow[i]
    }
}
