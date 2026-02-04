#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int i;
extern int lower_bound;
extern int upper_bound;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = lower_bound; i < upper_bound; i += step) {
        stack_usage_map[i] = 1;
        if (i + 1 < upper_bound)
            stack_usage_map[i + 1] = 1;
    }
}
