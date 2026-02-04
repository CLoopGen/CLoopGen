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
    int temp_dragon, temp_worm;
    for (k = 0; k < next_lunch; k++) {
        temp_dragon = lunch_dragon[k];
        temp_worm = lunch_worm[k];
        if ((temp_dragon == dragon1) && (temp_worm == worm1))
            return;
    }
}
