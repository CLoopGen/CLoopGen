#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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
int unstable_worms[240];
int N = 0;
int m;
int n;
int ii;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i < 400) ? (i % 3 == 0) : 0;
    }

    for (int i = 0; i < 400; i++) {
        worm[i].origin = (i % 5 == 0) ? i : (i - 1);
        worm[i].attack_codes[0] = (i % 7 != 0);
        worm[i].defense_codes[0] = (i % 11 != 0);
    }

    for (int i = 0; i < 240; i++) {
        unstable_worms[i] = 0;
    }

    N = 0;
}