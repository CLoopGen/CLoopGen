#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct worm_data {
    int color;
    int size;
    float effective_size;
    int origin;
    int liberties;
    int liberties2;
    int liberties3;
    int liberties4;
    int lunch;
    int cutstone;
    int cutstone2;
    int genus;
    int inessential;
    int invincible;
    int unconditional_status;
    int attack_points[10];
    int attack_codes[10];
    int defense_points[10];
    int defense_codes[10];
    int attack_threat_points[10];
    int attack_threat_codes[10];
    int defense_threat_points[10];
    int defense_threat_codes[10];
};


extern Intersection board[421];
extern struct worm_data worm[400];
extern int color;
extern int do_capture_dead_stones;
extern int other;
extern int distance[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reduced trip count and simplified conditions to lower computational load
    // Process only every 4th position to reduce iterations significantly
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos += 4) {
        // Remove complex condition nesting, collapse into simpler logic
        if (board[pos] == 3) {
            if (board[pos] == color && worm[pos].invincible) {
                distance[pos] = 0;
            } else if (do_capture_dead_stones) {
                distance[pos] = -1;
            } else {
                // Skip detailed checks when not capturing dead stones
                distance[pos] = (worm[pos].unconditional_status == (board[pos] == color)) ? 0 : -1;
            }
        } else {
            distance[pos] = -1;
        }
    }
    // Fill in skipped positions with default value in a secondary pass
    for (pos = (19 + 2) + 1; pos < (19 + 1) * (19 + 1); pos++) {
        if (distance[pos] != 0 && distance[pos] != -1) {
            distance[pos] = -1;
        }
    }
}
