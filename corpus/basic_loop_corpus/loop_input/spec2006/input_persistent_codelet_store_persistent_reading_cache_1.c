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
char active[400];
int k;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        if (i >= 21 && i < 400) {
            board[i] = (i % 7 == 0) ? 3 : ((i % 5 == 0) ? 1 : 2);
        } else {
            board[i] = 0;
        }
    }

    for (int i = 0; i < 400; i++) {
        worm[i].color = (i % 2) + 1;
        worm[i].size = i % 15;
        worm[i].effective_size = (float)(i % 10 + 5);
        worm[i].origin = i;
        worm[i].liberties = i % 4;
        worm[i].liberties2 = i % 5;
        worm[i].liberties3 = i % 6;
        worm[i].liberties4 = i % 7;
        worm[i].lunch = -1;
        worm[i].cutstone = 0;
        worm[i].cutstone2 = 0;
        worm[i].genus = i % 3;
        worm[i].inessential = (i % 10 == 0);
        worm[i].invincible = (i % 13 == 0);
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

    for (int i = 0; i < 400; i++) {
        active[i] = 1;
    }

    k = 0;
}