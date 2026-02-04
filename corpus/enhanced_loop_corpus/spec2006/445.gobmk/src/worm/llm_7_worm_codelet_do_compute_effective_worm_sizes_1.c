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


extern int board_size;
extern Intersection board[421];
extern struct worm_data worm[400];
extern int color;
extern int pos;
extern int distance[400];
extern int worms[400][36];
extern int nworms[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int prev_pos = (19 + 2) - 1;
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if (!(board[pos] != 3))
        continue;
    for (k = 0; k < 2 * (board_size - 1); k++)
        worms[pos][k] = (prev_pos >= (19 + 2)) ? worms[prev_pos][k] : 0;
    nworms[pos] = (prev_pos >= (19 + 2)) ? nworms[prev_pos] : 0;
    if (board[pos] & color) {
        distance[pos] = 0;
        worms[pos][0] = worm[pos].origin;
        nworms[pos]++;
    } else
        distance[pos] = -1;
    prev_pos = pos;
}
}
