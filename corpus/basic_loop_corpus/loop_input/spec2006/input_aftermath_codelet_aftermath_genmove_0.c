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
int color;
int do_capture_dead_stones;
int other;
int distance[400];
int pos;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= 21 && i < 400) ? 3 : 0;
    }

    for (int i = 0; i < 400; i++) {
        worm[i].color = (i % 2) ? 1 : 2;
        worm[i].invincible = (i % 17 == 0) ? 1 : 0;
        worm[i].unconditional_status = (i % 13 == 0) ? 0 : (i % 13 == 1) ? 1 : 2;
        worm[i].liberties = i % 5;
        worm[i].lunch = 0;
        worm[i].cutstone = 0;
        worm[i].cutstone2 = 0;
        worm[i].genus = 0;
        worm[i].inessential = 0;
        worm[i].size = 1;
        worm[i].effective_size = 1.0f;
        worm[i].origin = i;
        
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

    color = 1;
    do_capture_dead_stones = 0;
    other = 2;

    for (int i = 0; i < 400; i++) {
        distance[i] = -1;
    }

    pos = 0;
}