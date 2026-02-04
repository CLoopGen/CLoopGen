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


struct eyevalue {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
};


struct dragon_data2 {
    int origin;
    int adjacent[10];
    int neighbors;
    int hostile_neighbors;
    int moyo_size;
    float moyo_territorial_value;
    int safety;
    float weakness;
    float weakness_pre_owl;
    int escape_route;
    struct eyevalue genus;
    int heye;
    int lunch;
    int semeai;
    int semeai_margin_of_safety;
    int surround_status;
    int surround_size;
};


extern Intersection board[421];
extern struct worm_data worm[400];
extern struct dragon_data dragon[400];
extern struct dragon_data2 *dragon2;
extern int pos;
extern int dragon_status_known;
extern int ii;
extern char goal[400];
extern char escape_value[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ii = (19 + 2); ii < (19 + 1) * (19 + 1) + 10; ii++) {
    if (ii >= 400) continue;
    if (board[ii] == 3) {
        if (dragon_status_known) {
            int d_id = dragon[ii].id;
            int c_status = dragon[ii].crude_status;
            if (c_status == 1) {
                escape_value[ii] = 6;
            } else if (c_status == 3) {
                int er = dragon2[d_id].escape_route;
                int ms = dragon2[d_id].moyo_size;
                if (er > 5) escape_value[ii] = 4;
                if (ms > 5) escape_value[ii] = 4;
            }
        } else {
            if (board[ii] == board[pos] && goal[ii] == 0 && worm[ii].attack_codes[0] == 0) {
                escape_value[ii] = 2;
            }
        }
    }
}
}
