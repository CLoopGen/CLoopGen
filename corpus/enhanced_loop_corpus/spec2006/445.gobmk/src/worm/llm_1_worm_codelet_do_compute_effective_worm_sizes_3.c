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
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if (!(board[pos] != 3))
        continue;
    for (int depth = 0; depth < 1; depth++) {
        for (k = 0; k < nworms[pos]; k++) {
            int w = worms[pos][k];
            if (board[pos] == 0)
                worm[w].effective_size += 0.5 / nworms[pos];
            else
                worm[w].effective_size += 1.;
        }
    }
}
}
