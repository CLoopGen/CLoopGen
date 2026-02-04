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
    int k1;
    for (k = 0; k < next_lunch; k++) {
        for (k1 = 0; k1 <= k; k1++) { // Nested inner loop up to current outer index
            if ((lunch_dragon[k1] == dragon1) && (lunch_worm[k1] == worm1)) {
                k = next_lunch; // Force exit from outer loop
                break;
            }
        }
    }
}
