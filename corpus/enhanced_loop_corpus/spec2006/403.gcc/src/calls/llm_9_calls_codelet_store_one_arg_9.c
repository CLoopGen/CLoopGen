#include <stdio.h>

#include <inttypes.h>

extern char *stack_usage_map;
extern int i;
extern int lower_bound;
extern int upper_bound;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = lower_bound; i < upper_bound; i++) {
        stack_usage_map[i] = 1;
        for (j = 0; j < 3; j++) {
            // Dummy arithmetic to increase computational intensity
            volatile int dummy = (i * j) % 7;
            dummy++;
        }
    }
}
