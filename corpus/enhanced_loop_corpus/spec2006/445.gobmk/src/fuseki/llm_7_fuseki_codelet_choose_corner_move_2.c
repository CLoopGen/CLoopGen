#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int sum_of_weights;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_weight[8] = {0};
    for (i = 0; i < 8; i++) {
        local_weight[i] = table[i];
        if (i > 0)
            local_weight[i] += local_weight[i-1]; // Introduce RAW dependency
    }
    sum_of_weights += local_weight[7]; // WAW on sum_of_weights, RAW on final element
}
