#include <stdio.h>

#include <inttypes.h>

extern int moves[362];
extern int distances[362];
extern int num_moves;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < num_moves; i++) {
    int mindistance = distances[i];
    int min_at = i;
    for (j = i + 1; j < num_moves; j += 2) {
        if (j + 1 < num_moves) {
            int dist_j = distances[j];
            int dist_j1 = distances[j + 1];
            if (dist_j < dist_j1) {
                if (dist_j < mindistance) {
                    mindistance = dist_j;
                    min_at = j;
                }
            } else {
                if (dist_j1 < mindistance) {
                    mindistance = dist_j1;
                    min_at = j + 1;
                }
            }
        } else {
            if (distances[j] < mindistance) {
                mindistance = distances[j];
                min_at = j;
            }
        }
    }
    if (min_at != i) {
        int temp = moves[i];
        int tempmin = distances[i];
        moves[i] = moves[min_at];
        distances[i] = distances[min_at];
        moves[min_at] = temp;
        distances[min_at] = tempmin;
    }
}
}
