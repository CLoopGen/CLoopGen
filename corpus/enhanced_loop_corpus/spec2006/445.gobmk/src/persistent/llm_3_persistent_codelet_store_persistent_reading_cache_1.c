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
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Precompute valid indices in a separate array and iterate over them indirectly.
    // This simulates irregular or gather-style memory access patterns.
    int indices[400];
    int count = 0;
    for (int i = (19 + 2); i < (19 + 1) * (19 + 1); i++) {
        if (board[i] == 3) continue;  // Only include indices where board[i] != 3 is false (i.e., skip condition fails)
        indices[count++] = i;
    }
    for (int idx = 0; idx < count; idx++) {
        int k_val = indices[idx];
        if (((board[k_val]) == 1 || (board[k_val]) == 2) && worm[k_val].invincible)
            active[k_val] = 0;
    }
}
