#include <stdio.h>

#include <inttypes.h>

extern int goal_worm[15];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 30; k++) {
        int index = k % 15;
        goal_worm[index] = (goal_worm[index] * 2) ^ 1;
        goal_worm[index] += k / 15;
    }
}
