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
for (i = 0; i < n_vec; i++) {
    int32 j = 0;
    for (; j < n_dim; j++)
        mean[j] += data[i][j];
}
}
