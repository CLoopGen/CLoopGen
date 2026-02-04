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
    // Variant 1: Strided Memory Access Pattern
    // Instead of iterating row-major with natural index progression,
    // access the board and worm arrays with a fixed stride (e.g., every second element),
    // then handle remaining elements in a second pass to maintain coverage.
    int stride = 2;
    N = 0; // Reset counter

    // First pass: strided access
    for (m = 0; m < board_size; m++) {
        for (n = 0; n < board_size; n += stride) {
            ii = ((19 + 2) + m * (19 + 1) + n);
            if (board[ii] && worm[ii].origin == ii && worm[ii].attack_codes[0] != 0 && worm[ii].defense_codes[0] != 0) {
                unstable_worms[N] = ii;
                N++;
            }
        }
    }

    // Second pass: offset start by 1 for odd indices
    for (m = 0; m < board_size; m++) {
        for (n = 1; n < board_size; n += stride) {
            ii = ((19 + 2) + m * (19 + 1) + n);
            if (board[ii] && worm[ii].origin == ii && worm[ii].attack_codes[0] != 0 && worm[ii].defense_codes[0] != 0) {
                unstable_worms[N] = ii;
                N++;
            }
        }
    }
}
