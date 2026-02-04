#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int i;
extern int lower_bound;
extern int upper_bound;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0, i = lower_bound; i < upper_bound; i++, j++) {
        if (j % 2 == 0)
            stack_usage_map[i] = 1;
        else
            stack_usage_map[i] = stack_usage_map[i - 1]; // Introduces loop-carried dependence (RAW)
    }
}
