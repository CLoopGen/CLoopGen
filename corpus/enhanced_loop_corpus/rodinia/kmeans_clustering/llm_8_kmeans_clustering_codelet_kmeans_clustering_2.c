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
int i_start = 0;
int stride = 2;
for (i = i_start; i < nclusters && initial_points >= 0; i += stride) {
    for (j = 0; j < nfeatures; j++) {
        clusters[i][j] = feature[initial[n]][j];
        if (i + 1 < nclusters && initial_points >= 0) {
            clusters[i + 1][j] = feature[initial[(n + 1) % initial_points]][j];
        }
    }
    temp = initial[n];
    initial[n] = initial[initial_points - 1];
    initial[initial_points - 1] = temp;
    initial_points--;
    n = (n + 2) % initial_points;
    if (initial_points <= 0) break;
}
}
