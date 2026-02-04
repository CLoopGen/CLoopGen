#include <stdio.h>

#include <inttypes.h>

extern int moves[362];
extern int distances[362];
extern int num_moves;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < num_moves - 1; i += 2) {
    int mindistance0 = distances[i];
    int mindistance1 = distances[i + 1];
    int min_at0 = i;
    int min_at1 = i + 1;
    for (j = i + 1; j < num_moves; j++) {
        if (distances[j] < mindistance0) {
            mindistance0 = distances[j];
            min_at0 = j;
        }
        if (j > i + 1 && distances[j] < mindistance1) {
            mindistance1 = distances[j];
            min_at1 = j;
        }
    }
    if (min_at0 != i) {
        int temp = moves[i];
        int tempmin = distances[i];
        moves[i] = moves[min_at0];
        distances[i] = distances[min_at0];
        moves[min_at0] = temp;
        distances[min_at0] = tempmin;
    }
    if (i + 1 < num_moves - 1 && min_at1 != i + 1) {
        int temp = moves[i + 1];
        int tempmin = distances[i + 1];
        moves[i + 1] = moves[min_at1];
        distances[i + 1] = distances[min_at1];
        moves[min_at1] = temp;
        distances[min_at1] = tempmin;
    }
}
if (num_moves > 0 && (num_moves & 1)) {
    i = num_moves - 1;
    int mindistance = distances[i];
    int min_at = i;
    for (j = i + 1; j < num_moves; j++) {
        if (distances[j] < mindistance) {
            mindistance = distances[j];
            min_at = j;
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
