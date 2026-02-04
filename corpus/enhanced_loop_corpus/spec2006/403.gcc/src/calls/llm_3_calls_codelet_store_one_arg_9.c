#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int i;
extern int lower_bound;
extern int upper_bound;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive write in reverse order (descending index)
    for (i = upper_bound - 1; i >= lower_bound; i--)
        stack_usage_map[i] = 1;
}
