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
extern int color;
extern int do_capture_dead_stones;
extern int other;
extern int distance[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth = 0; depth < 2; depth++) {
        for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
            if (!(board[pos] != 3))
                continue;
            else if (board[pos] == color && worm[pos].invincible)
                distance[pos] = 0;
            else if (!do_capture_dead_stones && ((board[pos] == other && worm[pos].unconditional_status == 0) || (board[pos] == color && worm[pos].unconditional_status == 1)))
                distance[pos] = 0;
            else
                distance[pos] = -1;
        }
    }
}
