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
    for (k = 0; k < next_lunch && k < 240; k += 2) {
        if ((lunch_dragon[k] == dragon1) && (lunch_worm[k] == worm1)) {
            break;
        }
        if (k + 1 < next_lunch && lunch_dragon[k + 1] == dragon1 && lunch_worm[k + 1] == worm1) {
            k++;
            break;
        }
    }
}
