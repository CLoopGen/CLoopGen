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

int board_size = 19;
Intersection board[421];
struct worm_data worm[400];
int color = 1;
int pos;
int distance[400];
int worms[400][36];
int nworms[400];
int k;

void init_vars() {
    // Initialize board_size to 19 as implied by the loop bounds (19+2) and (19+1)*(19+1)
    board_size = 19;

    // Ensure board is large enough: indices go up to (19+1)*(19+1) = 400, so 421 is safe
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= 21 && i < 400) ? 3 : 0;  // Set valid positions to 3 to enter condition
    }

    // Initialize worm data
    for (int i = 0; i < 400; i++) {
        worm[i].color = 1;
        worm[i].origin = i;
        worm[i].size = 1;
        worm[i].effective_size = 1.0f;
        worm[i].liberties = 4;
        worm[i].liberties2 = 4;
        worm[i].liberties3 = 4;
        worm[i].liberties4 = 4;
        worm[i].lunch = -1;
        worm[i].cutstone = -1;
        worm[i].cutstone2 = -1;
        worm[i].genus = 0;
        worm[i].inessential = 0;
        worm[i].invincible = 0;
        worm[i].unconditional_status = 0;
        for (int j = 0; j < 10; j++) {
            worm[i].attack_points[j] = -1;
            worm[i].attack_codes[j] = 0;
            worm[i].defense_points[j] = -1;
            worm[i].defense_codes[j] = 0;
            worm[i].attack_threat_points[j] = -1;
            worm[i].attack_threat_codes[j] = 0;
            worm[i].defense_threat_points[j] = -1;
            worm[i].defense_threat_codes[j] = 0;
        }
    }

    // Initialize color to non-zero so that (board[pos] & color) can be true
    color = 1;

    // Initialize distance, worms, nworms arrays
    for (int i = 0; i < 400; i++) {
        distance[i] = -1;
        nworms[i] = 0;
        for (int j = 0; j < 36; j++) {
            worms[i][j] = 0;
        }
    }

    // The loop uses pos from (19+2)=21 to (19+1)*(19+1)-1=399, so ensure these are valid
    // No further initialization needed — already covered above
}