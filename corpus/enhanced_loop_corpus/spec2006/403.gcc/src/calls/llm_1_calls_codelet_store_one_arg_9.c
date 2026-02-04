#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int i;
extern int lower_bound;
extern int upper_bound;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = lower_bound; i < upper_bound; i++) {
        for (int j = 0; j < 1; j++) {
            stack_usage_map[i] = 1;
        }
    }
}
