#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *mean;
extern int32 n_dim;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < n_dim; i++)
    mean[i] = 0.;

}
