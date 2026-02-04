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
    float **temp_clusters = clusters + 1;
    for (int j = 0; j < nclusters - 1; j++) {
        temp_clusters[j] = clusters[j] + nfeatures;
    }
}
