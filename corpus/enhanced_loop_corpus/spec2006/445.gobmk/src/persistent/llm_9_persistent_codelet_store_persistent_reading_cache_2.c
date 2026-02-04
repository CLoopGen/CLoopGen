#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 4;
for (k = 20; k < 361; k += stride) {  // Modified trip count and step size to reduce iterations but increase arithmetic per iteration
    int offsets[] = {20, -1, -20, 1};
    int num_offsets = 4;
    int trigger = 0;
    for (int j = 0; j < num_offsets; j++) {
        int neighbor = k + offsets[j];
        // Bounds check for board access
        if (neighbor < 0 || neighbor >= 421) continue;
        if (j == 1 || j == 3) {  // Horizontal neighbors: ensure same row
            if ((k / 20) != (neighbor / 20)) continue;
        }
        if (board[neighbor] == 0 && active[neighbor] == 2) {
            trigger = 1;
            break;
        }
    }
    if (!trigger) continue;
    if (((board[k]) == 1 || (board[k]) == 2) || active[k] != 0)
        continue;
    active[k] = 3;
}
}
