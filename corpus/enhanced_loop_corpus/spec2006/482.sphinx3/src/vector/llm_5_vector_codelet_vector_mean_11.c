#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *mean;
extern int32 n_dim;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < n_dim; i++) {
    if (i % 2 == 0)
        continue;
    mean[i] = 0.;
}
mean[0] = 0.; // Ensure all elements are set, including skipped ones due to continue
}
