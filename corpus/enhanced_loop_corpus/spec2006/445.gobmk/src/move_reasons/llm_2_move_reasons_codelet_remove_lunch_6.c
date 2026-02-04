#include <stdio.h>

#include <inttypes.h>

extern int lunch_dragon[240];
extern int lunch_worm[240];
extern int next_lunch;
extern int k;
extern int dragon1;
extern int worm1;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    for (k = 0; k < next_lunch; k += 2) {
        if ((lunch_dragon[k] == dragon1) && (lunch_worm[k] == worm1)) {
            break;
        }
    }
    // Adjust k if the exact match was skipped due to stride
    if (k >= next_lunch && (next_lunch & 1)) {
        k = next_lunch - 1;
        if ((lunch_dragon[k] == dragon1) && (lunch_worm[k] == worm1)) {
            // Match at last odd index
        } else {
            k = next_lunch;
        }
    }
}
