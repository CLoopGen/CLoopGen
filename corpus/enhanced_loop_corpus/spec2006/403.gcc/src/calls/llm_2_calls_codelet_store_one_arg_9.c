#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int i;
extern int lower_bound;
extern int upper_bound;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (i = lower_bound; i < upper_bound; i += 2)
        stack_usage_map[i] = 1;
}
