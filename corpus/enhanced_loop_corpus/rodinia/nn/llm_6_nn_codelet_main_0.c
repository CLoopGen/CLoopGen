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
    double *distances = (double *)malloc(k * sizeof(double));
    for (j = 0; j < k; j++) {
        distances[j] = 10000;
        neighbors[j].dist = distances[j];
    }
    free(distances);
}
