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
    for (j = i + 1; j < num_moves; j++) {
        if (distances[j] < mindistance) {
            mindistance = distances[j];
            min_at = j;
        }
    }
    if (min_at != i) {
        // Introduce a WAW dependency by updating distances before moves
        // Also create a WAR hazard by reusing mindistance after write
        distances[min_at] = distances[i];  // Write before later read in same iteration
        moves[min_at] = moves[i];
        distances[i] = mindistance;
        moves[i] = moves[min_at];  // Re-read moves[min_at] after prior write → WAR
    }
}
}
