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

Intersection board[421];
struct worm_data worm[400];
int pos;
int worms[400][36];
int nworms[400];
int k;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= (19 + 2) && i < (19 + 1) * (19 + 1)) ? 3 : 0;
    }

    for (int i = 0; i < 400; i++) {
        worm[i].color = 0;
        worm[i].size = 1;
        worm[i].effective_size = 0.0f;
        worm[i].origin = 0;
        worm[i].liberties = 0;
        worm[i].liberties2 = 0;
        worm[i].liberties3 = 0;
        worm[i].liberties4 = 0;
        worm[i].lunch = -1;
        worm[i].cutstone = 0;
        worm[i].cutstone2 = 0;
        worm[i].genus = 0;
        worm[i].inessential = 0;
        worm[i].invincible = 0;
        worm[i].unconditional_status = 0;
        for (int j = 0; j < 10; j++) {
            worm[i].attack_points[j] = 0;
            worm[i].attack_codes[j] = 0;
            worm[i].defense_points[j] = 0;
            worm[i].defense_codes[j] = 0;
            worm[i].attack_threat_points[j] = 0;
            worm[i].attack_threat_codes[j] = 0;
            worm[i].defense_threat_points[j] = 0;
            worm[i].defense_threat_codes[j] = 0;
        }
    }

    for (int i = 0; i < 400; i++) {
        nworms[i] = 0;
        for (int j = 0; j < 36; j++) {
            worms[i][j] = 0;
        }
    }

    for (int p = (19 + 2); p < (19 + 1) * (19 + 1); p++) {
        nworms[p] = (p % 7 == 0) ? 0 : (p % 5 + 1);
        for (int w_idx = 0; w_idx < nworms[p]; w_idx++) {
            worms[p][w_idx] = (p + w_idx) % 400;
        }
    }

    pos = 0;
    k = 0;
}