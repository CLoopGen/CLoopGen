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

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 400; i++) {
        pos = 21 + (i * 7) % (19 * 19 - 1);
        if ((board[pos] != 3)) {
            worm[pos].origin = 0;
            worm[pos].liberties = 1;
            worm[pos].size = worm[pos].size > 0 ? worm[pos].size - 1 : 0;
        }
    }
}
