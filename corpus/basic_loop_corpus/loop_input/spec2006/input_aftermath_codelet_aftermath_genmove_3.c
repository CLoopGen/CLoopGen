#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int delta[8] = { -40, -1, 1, 40, -39, 39, -41, 41 }; // Sample deltas for 2D grid movement
Intersection board[421];
int distance[400];
int k;
int move;
int init_done = 0;

void init_vars() {
    if (init_done) return;
    
    // Initialize delta with small offsets to stay within board bounds
    for (int i = 0; i < 8; i++) {
        delta[i] = (i < 4) ? (i == 0 ? -40 : (i == 1 ? -1 : (i == 2 ? 1 : 40))) : 0;
    }
    
    // Clear board and distance arrays
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 7 == 0) ? 3 : 0; // Set some positions to 3 to allow condition failure
    }
    for (int i = 0; i < 400; i++) {
        distance[i] = 100 + (i % 50); // Ensure valid decreasing path
    }
    
    // Set initial move within valid range, avoiding edges
    move = 200;
    distance[move] = 50;
    // Create a valid pos2 that satisfies the condition
    int valid_dir = 1;
    int pos2 = move + delta[valid_dir];
    if (pos2 >= 0 && pos2 < 400) {
        board[pos2] = 0;
        distance[pos2] = distance[move] - 1;
        // Force first iteration to find this
        for (int i = 0; i < 4; i++) {
            int p = move + delta[i];
            if (p == pos2) continue;
            if (p >= 0 && p < 421) {
                board[p] = 3; // Make others fail first condition
            }
        }
    }

    init_done = 1;
}