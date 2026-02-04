#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int under_control[400];
extern int distance[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_control[400];
    int i;
    // First pass: eliminate loop-carried dependency by using local storage
    for (i = (19 + 2); i < (19 + 1) * (19 + 1); i++) {
        if (!(board[i] != 3)) {
            temp_control[i] = under_control[i]; // preserve old value
        } else if (distance[i] == -1) {
            temp_control[i] = 0;
        } else {
            temp_control[i] = 1;
        }
    }
    // Second pass: write back to shared array, creating WAW dependency intentionally
    for (i = (19 + 2); i < (19 + 1) * (19 + 1); i++) {
        under_control[i] = temp_control[i];
    }
}
