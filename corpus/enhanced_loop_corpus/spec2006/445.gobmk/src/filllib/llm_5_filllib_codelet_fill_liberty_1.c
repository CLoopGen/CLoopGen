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


extern int delta[8];
extern Intersection board[421];
extern struct worm_data worm[400];
extern struct dragon_data dragon[400];
extern struct dragon_data2 *dragon2;
extern int k;
extern int pos;
extern int potential_color[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if (!((board[pos]) == 1 || (board[pos]) == 2))
        continue;

    if (worm[pos].inessential)
        continue;

    int d_id = dragon[pos].id;
    int safety_val = dragon2[d_id].safety;

    if (safety_val == 5)
        continue;

    int status = dragon[pos].status;

    if (status == 1) {
        for (k = 0; k < 12; k++) {
            int d = delta[k % 8];
            if (k >= 8) {
                if (board[pos + d] != 0)
                    continue;
                d *= 2;
            }
            if (board[pos + d] == 0)
                potential_color[pos + d] |= board[pos];
        }
        continue;
    }

    if (status == 0) {
        for (k = 0; k < 4; k++) {
            int pos2 = pos + delta[k];
            if (board[pos2] == 0)
                potential_color[pos2] |= (1 + 2 - (board[pos]));
        }
        continue;
    }

    for (k = 0; k < 4; k++) {
        int pos2 = pos + delta[k];
        if (board[pos2] == 0)
            potential_color[pos2] |= (1 + 2 - (board[pos]));
    }
    for (k = 0; k < 12; k++) {
        int d = delta[k % 8];
        if (k >= 8) {
            if (board[pos + d] != 0)
                continue;
            d *= 2;
        }
        if (board[pos + d] == 0)
            potential_color[pos + d] |= board[pos];
    }
}
}
