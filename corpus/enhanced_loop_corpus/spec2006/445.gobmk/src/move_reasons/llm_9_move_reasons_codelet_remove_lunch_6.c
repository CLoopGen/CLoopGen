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
    int found = 0;
    for (k = 0; k < next_lunch && !found; k++) {
        int diff1 = lunch_dragon[k] - dragon1;
        int diff2 = lunch_worm[k] - worm1;
        if ((diff1 | diff2) == 0) {
            found = 1;
        }
    }
    if (found) k--;
}
