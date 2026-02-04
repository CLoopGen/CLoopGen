#include <stdio.h>

#include <inttypes.h>

extern int moves[362];
extern int distances[362];
extern int num_moves;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < num_moves; i += 2) {
    int mindistance1 = distances[i];
    int min_at1 = i;
    int mindistance2 = (i + 1 < num_moves) ? distances[i + 1] : mindistance1;
    int min_at2 = i + 1;
    for (j = i + 1; j < num_moves; j++) {
        if (distances[j] < mindistance1) {
            mindistance1 = distances[j];
            min_at1 = j;
        }
        if (j > i + 1 && distances[j] < mindistance2) {
            mindistance2 = distances[j];
            min_at2 = j;
        }
    }
    if (min_at1 != i) {
        int temp = moves[i];
        int tempmin = distances[i];
        moves[i] = moves[min_at1];
        distances[i] = distances[min_at1];
        moves[min_at1] = temp;
        distances[min_at1] = tempmin;
    }
    if ((i + 1 < num_moves) && min_at2 != i + 1 && min_at2 != i) {
        int temp = moves[i + 1];
        int tempmin = distances[i + 1];
        moves[i + 1] = moves[min_at2];
        distances[i + 1] = distances[min_at2];
        moves[min_at2] = temp;
        distances[min_at2] = tempmin;
    }
}
}
