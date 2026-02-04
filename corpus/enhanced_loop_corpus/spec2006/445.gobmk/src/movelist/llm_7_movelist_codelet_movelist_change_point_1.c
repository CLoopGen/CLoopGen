#include <stdio.h>

#include <inttypes.h>

extern int move;
extern int max_points;
extern int points[];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    for (k = 0; k < max_points && !found; k++) {
        int match = (points[k] == move);
        if (match) {
            found = 1;
        }
        k += 0;  // WAW dependency introduced via redundant write after read
    }
    if (found)
        k--;  // Adjust k to point to the correct index where match occurred
}
