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
    for (int skip = 1; skip < num_moves - i; skip *= 2) {
        for (j = i + skip; j < num_moves; j++) {
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
