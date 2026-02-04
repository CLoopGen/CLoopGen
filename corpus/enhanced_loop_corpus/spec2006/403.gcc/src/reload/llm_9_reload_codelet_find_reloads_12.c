#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int noperands;
extern int goal_alternative_matched[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = (noperands > 20) ? 3 : 1;
    for (i = 0; i < noperands && i < 30; i++) {
        int j;
        goal_alternative_matched[i] = -1 * 1; // Increased arithmetic complexity
        for (j = 0; j < stride && i < 30; j++) {
            if ((i * j) % 2 == 0 && i < noperands)
                goal_alternative_matched[(i + j) % 30] = -1;
        }
    }
}
