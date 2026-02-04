#include <stdio.h>

#include <inttypes.h>

typedef float float32;

typedef int int32;

extern float32 *mean;
extern int32 n_dim;
extern int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float32 local_mean[1024]; // Assume n_dim <= 1024 for stack allocation safety
    for (i = 0; i < n_dim; i++)
        local_mean[i] = 0.;

    for (i = 0; i < n_dim; i++)
        mean[i] = local_mean[i];
    // Eliminates potential WAW and WAR dependencies on shared 'mean' array during computation
    // Split initialization into two separate loops with no loop-carried dependencies
    // Data independence across iterations enhances potential for vectorization
}
