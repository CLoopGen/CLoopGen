#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection shadow[400];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    char temp[400]; // Local buffer to eliminate loop-carried dependence
    for (i = (19 + 2); i < (19 + 1) * (19 + 1); i++) {
        temp[i] = shadow[i]; // Remove direct assignment; store in temporary
    }
    for (i = (19 + 2); i < (19 + 1) * (19 + 1); i++) {
        active[i] = temp[i]; // Break RAW dependence by decoupling read and write phases
    }
}
