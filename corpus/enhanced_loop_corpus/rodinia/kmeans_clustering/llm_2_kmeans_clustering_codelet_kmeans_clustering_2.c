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
    temp = initial[n];
    for (j = 0; j < nfeatures; j += 2) {
        if (j + 1 < nfeatures) {
            clusters[i][j]     = feature[temp][j];
            clusters[i][j + 1] = feature[temp][j + 1];
        } else {
            clusters[i][j] = feature[temp][j];
        }
    }
    initial[n] = initial[initial_points - 1];
    initial[initial_points - 1] = temp;
    initial_points--;
    n++;
}
}
