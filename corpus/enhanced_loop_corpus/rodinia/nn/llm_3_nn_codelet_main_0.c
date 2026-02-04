#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct neighbor {
    char entry[49];
    double dist;
};


extern int j;
extern int k;
extern struct neighbor *neighbors;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access pattern
    for (j = k - 1; j >= 0; j--) {
        neighbors[j].dist = 10000;
    }
}
