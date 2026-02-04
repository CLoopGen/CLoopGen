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
extern int unstable_worms[240];
extern int N;
extern int m;
extern int n;
extern int ii;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int stride = 2;
for (m = 0; m < board_size; m += stride)
    for (n = 0; n < board_size; n += stride) {
        ii = ((19 + 2) + (m) * (19 + 1) + (n));
        if (board[ii] && worm[ii].origin == ii && worm[ii].attack_codes[0] != 0 && worm[ii].defense_codes[0] != 0) {
            if (N < 240) { // prevent buffer overflow
                unstable_worms[N] = ii;
                N++;
            }
        }
    }
// Complete remaining elements with single iteration step if needed
for (m = 1; m < board_size; m += 2)
    for (n = 1; n < board_size; n += 2) {
        ii = ((19 + 2) + (m) * (19 + 1) + (n));
        if (board[ii] && worm[ii].origin == ii && worm[ii].attack_codes[0] != 0 && worm[ii].defense_codes[0] != 0) {
            if (N < 240) {
                unstable_worms[N] = ii;
                N++;
            }
        }
    }
}
