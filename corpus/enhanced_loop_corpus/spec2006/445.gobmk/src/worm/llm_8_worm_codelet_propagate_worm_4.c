#include <stdio.h>

#include <inttypes.h>

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


extern struct worm_data worm[400];
extern int pos;
extern int k;
extern int num_stones;
extern int stones[361];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < num_stones; k += 2) {
        if (k + 1 < num_stones && stones[k] != pos) {
            worm[stones[k]] = worm[pos];
            worm[stones[k + 1]] = worm[pos];
        }
        else if (stones[k] != pos) {
            worm[stones[k]] = worm[pos];
        }
    }
}
