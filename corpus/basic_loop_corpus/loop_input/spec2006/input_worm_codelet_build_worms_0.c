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

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= 21 && i < 400) ? ((i % 4) + 1) : 3;
    }
    
    for (int i = 0; i < 400; i++) {
        worm[i].color = i % 3;
        worm[i].size = (i % 15) + 1;
        worm[i].effective_size = (float)(i % 10) + 1.0f;
        worm[i].origin = -1;
        worm[i].liberties = (i % 5) + 1;
        worm[i].liberties2 = (i % 6) + 1;
        worm[i].liberties3 = (i % 7) + 1;
        worm[i].liberties4 = (i % 8) + 1;
        worm[i].lunch = -1;
        worm[i].cutstone = 0;
        worm[i].cutstone2 = 0;
        worm[i].genus = i % 3;
        worm[i].inessential = (i % 10) < 3;
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
    
    pos = 0;
}