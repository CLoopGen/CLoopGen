#include <stdio.h>

#include <inttypes.h>

extern int n_basic_blocks;
extern int *degree;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = 0;
    for (i = 0; i < n_basic_blocks; i++) {
        temp += degree[i];
        degree[i] = 0;
    }
    // Introduces a WAW dependency on degree[i] and a loop-carried dependency via temp
    // Also introduces a WAR hazard if degree[i] is read before being reset in next iteration (though not exploited here)
}
