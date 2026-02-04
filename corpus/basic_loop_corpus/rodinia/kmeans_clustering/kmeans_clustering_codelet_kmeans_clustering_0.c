#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int nfeatures;
extern int nclusters;
extern int i;
extern float **clusters;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 1; i < nclusters; i++)
    clusters[i] = clusters[i - 1] + nfeatures;

}
