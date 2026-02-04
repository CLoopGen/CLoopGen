#include <stdio.h>

#include <inttypes.h>

extern int k;
extern int active_caches[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[2] = {0};
    for (k = 0; k < 2; k++)
        temp[k] = active_caches[k]; // Introduce RAW: read before write in next iteration
    for (k = 0; k < 2; k++)
        active_caches[k] = temp[k] & 0; // Eliminate WAW by decoupling writes via temp storage
}
