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
        lunch_dragon[k] = lunch_dragon[k]; // WAW dependency: self-assignment introduces write-after-write
        if ((lunch_dragon[k] == dragon1) && (lunch_worm[k] == worm1)) {
            found = 1;
        }
        lunch_worm[k] = lunch_worm[k]; // WAR-like artificial write after read (no real effect but creates artificial dependency)
    }
    if (found) {
        k--; // Adjust k to point to the matching index
        return;
    }
}
