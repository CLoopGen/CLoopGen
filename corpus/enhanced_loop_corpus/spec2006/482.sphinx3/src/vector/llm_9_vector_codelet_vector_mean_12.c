#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *mean;
extern float32 **data;
extern int32 n_vec;
extern int32 n_dim;
extern int32 i;
extern int32 j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n_vec; i += 2) {  // Reduced trip count by increasing step size
    for (j = 0; j < n_dim; j += 2) {  // Reduced inner loop iterations and increased stride
        mean[j] += data[i][j];
        if (j + 1 < n_dim) {
            mean[j + 1] += data[i][j + 1];
        }
    }
    if (i + 1 < n_vec) {
        for (j = 0; j < n_dim; j++) {
            mean[j] += data[i + 1][j];
        }
    }
}
}
