#include <stdio.h>

#include <inttypes.h>

extern int moves[362];
extern int distances[362];
extern int num_moves;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int index[362];
for (int k = 0; k < num_moves; k++) {
    index[k] = k;
}
for (i = 0; i < num_moves; i++) {
    int min_idx = index[i];
    int mindistance = distances[min_idx];
    int min_at = i;
    for (j = i + 1; j < num_moves; j++) {
        int curr_idx = index[j];
        if (distances[curr_idx] < mindistance) {
            mindistance = distances[curr_idx];
            min_at = j;
        }
    }
    if (min_at != i) {
        int temp = index[i];
        index[i] = index[min_at];
        index[min_at] = temp;
    }
}
for (i = 0; i < num_moves; i++) {
    int src = index[i];
    int temp_move = moves[src];
    int temp_dist = distances[src];
    moves[src] = moves[i];
    distances[src] = distances[i];
    moves[i] = temp_move;
    distances[i] = temp_dist;
}
}
