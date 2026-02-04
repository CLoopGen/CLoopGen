#include <stdio.h>

#include <inttypes.h>

extern int goal_worm[15];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 5; k++) {
        for (int j = 0; j < 3; j++) {
            goal_worm[k * 3 + j] = 0;
        }
    }
}
