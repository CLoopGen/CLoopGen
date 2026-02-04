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
for (int i = 0; i < 1; i++) {
    for (j = 0; j < k; j++) {
        neighbors[j].dist = 10000;
    }
}
}
