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

Intersection board[421];
struct worm_data worm[400];
struct dragon_data dragon[400];
int aa_status[400];
char safe_stones[400];
int other;
int pos;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= 21 && i < 400) ? ((i % 7 == 0) ? other : (i % 5 == 0 ? 3 : (other ^ 1))) : 0;
    }

    for (int i = 0; i < 400; i++) {
        worm[i].color = i % 2;
        worm[i].size = i % 15 + 1;
        worm[i].effective_size = (float)(i % 10 + 1);
        worm[i].origin = i;
        worm[i].liberties = i % 5;
        worm[i].liberties2 = i % 4;
        worm[i].liberties3 = i % 3;
        worm[i].liberties4 = i % 2;
        worm[i].lunch = -1;
        worm[i].cutstone = -1;
        worm[i].cutstone2 = -1;
        worm[i].genus = i % 3;
        worm[i].inessential = 0;
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
        if (i % 7 == 0) {
            worm[i].attack_codes[0] = 1;
        }
        if (i % 11 == 0) {
            worm[i].defense_codes[0] = 1;
        }
    }

    for (int i = 0; i < 400; i++) {
        dragon[i].color = i % 2;
        dragon[i].id = i;
        dragon[i].origin = i;
        dragon[i].size = i % 20 + 1;
        dragon[i].effective_size = (float)(i % 15 + 1);
        dragon[i].crude_status = i % 4;
        dragon[i].owl_threat_status = 0;
        dragon[i].owl_status = 0;
        dragon[i].owl_attack_point = -1;
        dragon[i].owl_attack_code = 0;
        dragon[i].owl_attack_certain = 0;
        dragon[i].owl_second_attack_point = -1;
        dragon[i].owl_defense_point = -1;
        dragon[i].owl_defense_code = 0;
        dragon[i].owl_defense_certain = 0;
        dragon[i].owl_second_defense_point = -1;
        dragon[i].status = (i % 13 == 0) ? 0 : ((i % 17 == 0) ? 2 : 1);
        dragon[i].owl_attack_kworm = -1;
        dragon[i].owl_defense_kworm = -1;
    }

    for (int i = 0; i < 400; i++) {
        aa_status[i] = 0;
        safe_stones[i] = (i % 9 == 0) ? 1 : 0;
    }

    other = 1;
    pos = 0;
}