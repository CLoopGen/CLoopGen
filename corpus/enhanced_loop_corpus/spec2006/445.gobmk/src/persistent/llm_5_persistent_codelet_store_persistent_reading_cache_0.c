#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection shadow[400];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = (19 + 2); k < (19 + 1) * (19 + 1); k++) {
    if (shadow[k] == 0) {
        continue;
    }
    active[k] = shadow[k];
}
}
