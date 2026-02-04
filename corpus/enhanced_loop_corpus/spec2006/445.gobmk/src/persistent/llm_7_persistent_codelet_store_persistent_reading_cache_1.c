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
    int temp_active[400];
    for (int idx = (19 + 2); idx < (19 + 1) * (19 + 1); idx++) {
        k = idx; // Eliminate loop-carried WAW on k by decoupling iteration variable
        if (!(board[k] != 3))
            continue;
        if (((board[k]) == 1 || (board[k]) == 2) && worm[k].invincible)
            temp_active[k] = 0; // Remove WAR/WAW on active[] by using temporary storage
    }
    // Write back to active array outside the loop to eliminate loop-carried dependencies
    for (int idx = (19 + 2); idx < (19 + 1) * (19 + 1); idx++) {
        if (temp_active[idx])
            active[idx] = temp_active[idx];
    }
}
