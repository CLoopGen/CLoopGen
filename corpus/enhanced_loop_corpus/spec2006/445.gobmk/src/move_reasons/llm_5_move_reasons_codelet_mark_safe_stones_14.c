#include <stdio.h>

#include <inttypes.h>

struct dragon_data {
    int color;
    int id;
    int origin;
    int size;
    float effective_size;
    int crude_status;
    int owl_threat_status;
    int owl_status;
    int owl_attack_point;
    int owl_attack_code;
    int owl_attack_certain;
    int owl_second_attack_point;
    int owl_defense_point;
    int owl_defense_code;
    int owl_defense_certain;
    int owl_second_defense_point;
    int status;
    int owl_attack_kworm;
    int owl_defense_kworm;
};


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


extern struct dragon_data dragon[400];
extern Intersection board[421];
extern struct worm_data worm[400];
extern int color;
extern  char saved_dragons[400];
extern  char saved_worms[400];
extern char safe_stones[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    safe_stones[pos] = 0;

    if (board[pos] == (1 + 2 - color)) {
        if (dragon[pos].status != 0 && !(worm[pos].attack_codes[0] != 0 && worm[pos].defense_codes[0] == 0))
            safe_stones[pos] = 1;
        continue;
    }

    if (board[pos] == color) {
        if (!((worm[pos].attack_codes[0] != 0 && (worm[pos].defense_codes[0] == 0 || !saved_worms[pos])) || dragon[pos].status == 0)) {
            if (saved_dragons[pos])
                safe_stones[pos] = 2;
            else if (dragon[pos].status != 2)
                safe_stones[pos] = 1;
        }
    }
}
}
