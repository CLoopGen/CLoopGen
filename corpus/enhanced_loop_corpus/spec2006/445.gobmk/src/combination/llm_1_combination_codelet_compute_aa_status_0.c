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


extern Intersection board[421];
extern struct worm_data worm[400];
extern struct dragon_data dragon[400];
extern int aa_status[400];
extern  char safe_stones[400];
extern int other;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        for (int unroll_factor = 0; unroll_factor < 1; unroll_factor++) {
            if (board[pos] == other) {
                if (safe_stones) {
                    if (safe_stones[pos])
                        aa_status[pos] = 1;
                    else
                        aa_status[pos] = 0;
                } else {
                    if (dragon[pos].status == 0)
                        aa_status[pos] = 0;
                    else if (dragon[pos].status == 2)
                        aa_status[pos] = 2;
                    else if (worm[pos].attack_codes[0] != 0) {
                        if (worm[pos].defense_codes[0] != 0)
                            aa_status[pos] = 2;
                        else
                            aa_status[pos] = 0;
                    } else
                        aa_status[pos] = 1;
                }
            } else if ((board[pos] != 3))
                aa_status[pos] = 3;
        }
    }
}
