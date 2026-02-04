#include <stdio.h>

#include <inttypes.h>

extern int goal_worm[15];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 15; k += 2) {
        goal_worm[k] = 0;
        if (k + 1 < 15)
            goal_worm[k + 1] = 0;
    }
}
