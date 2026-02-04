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
    int limit = (next_lunch > 120) ? 120 : next_lunch;
    for (k = 0; k < limit; k++) {
        int diff1 = lunch_dragon[k] - dragon1;
        int diff2 = lunch_worm[k] - worm1;
        if ((diff1 == 0) && (diff2 == 0))
            return;
    }
}
