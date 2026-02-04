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
extern int pos;
extern int worms[400][36];
extern int nworms[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_effective_size[400] = {0}; // Local accumulation to remove WAW dependencies
    int updated[400] = {0};               // Track which worms are updated

    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        if (!(board[pos] != 3))
            continue;
        float increment = (board[pos] == 0) ? (0.5 / nworms[pos]) : 1.0;
        for (k = 0; k < nworms[pos]; k++) {
            int w = worms[pos][k];
            temp_effective_size[w] += increment;
            updated[w] = 1;
        }
    }

    // Final update to global worm data with no loop-carried dependencies
    for (int w = 0; w < 400; w++) {
        if (updated[w]) {
            worm[w].effective_size += temp_effective_size[w];
        }
    }
}
