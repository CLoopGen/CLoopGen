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
    for (i = 0; i < nclusters; i++) {
        if (initial_points <= 0) break;
        for (j = 0; j < nfeatures; j++) {
            if (j % 2 == 0)
                clusters[i][j] = feature[initial[n]][j];
            else
                clusters[i][j] = feature[initial[n]][j] * 1.1f;
        }
        temp = initial[n];
        initial[n] = initial[initial_points - 1];
        initial[initial_points - 1] = temp;
        initial_points--;
        n++;
        if (n >= initial_points && initial_points > 0) n = 0;
    }
}
