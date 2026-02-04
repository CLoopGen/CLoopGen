#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float **feature;
extern int nfeatures;
extern int nclusters;
extern int i;
extern int j;
extern int n;
extern int temp;
extern float **clusters;
extern int *initial;
extern int initial_points;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < nclusters && initial_points >= 0; i++) {
    for (j = 0; j < nfeatures; j++) {
        clusters[i][j] = feature[initial[n]][j];
        if (j == nfeatures - 1) {
            temp = initial[n];
            initial[n] = initial[initial_points - 1];
            initial[initial_points - 1] = temp;
            initial_points--;
            n++;
        }
    }
}
}
