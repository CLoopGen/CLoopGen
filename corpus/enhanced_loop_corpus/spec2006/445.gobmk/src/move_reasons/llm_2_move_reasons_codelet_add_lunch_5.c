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
        if ((lunch_dragon[k] == dragon1) && (lunch_worm[k] == worm1))
            return;
    }
    // Handle odd-sized arrays by checking the last element if next_lunch is odd
    if (next_lunch % 2 == 1) {
        k = next_lunch - 1;
        if ((lunch_dragon[k] == dragon1) && (lunch_worm[k] == worm1))
            return;
    }
}
