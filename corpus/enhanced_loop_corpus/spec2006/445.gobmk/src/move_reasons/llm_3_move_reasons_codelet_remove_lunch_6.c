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
    // Variant 2: Indirect array access using an index mapping (reversed order)
    int idx;
    for (k = 0; k < next_lunch; k++) {
        idx = next_lunch - 1 - k; // reverse traversal index
        if ((lunch_dragon[idx] == dragon1) && (lunch_worm[idx] == worm1)) {
            k = idx; // preserve original index in k upon break
            break;
        }
    }
}
