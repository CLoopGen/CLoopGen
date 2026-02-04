#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

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

struct dragon_data dragon[400];
Intersection board[421];
struct worm_data worm[400];
int color;
char saved_dragons[400];
char saved_worms[400];
char safe_stones[400];
int pos;

void init_vars() {
    for (int i = 0; i < 400; i++) {
        dragon[i].color = 1;
        dragon[i].id = i;
        dragon[i].origin = i;
        dragon[i].size = 5 + (i % 10);
        dragon[i].effective_size = 5.0f + (i % 10);
        dragon[i].crude_status = 1;
        dragon[i].owl_threat_status = 0;
        dragon[i].owl_status = 1;
        dragon[i].owl_attack_point = 0;
        dragon[i].owl_attack_code = 0;
        dragon[i].owl_attack_certain = 0;
        dragon[i].owl_second_attack_point = 0;
        dragon[i].owl_defense_point = 0;
        dragon[i].owl_defense_code = 0;
        dragon[i].owl_defense_certain = 0;
        dragon[i].owl_second_defense_point = 0;
        dragon[i].status = (i % 3); 
        dragon[i].owl_attack_kworm = 0;
        dragon[i].owl_defense_kworm = 0;

        worm[i].color = 1 + (i % 2);
        worm[i].size = 4 + (i % 8);
        worm[i].effective_size = 4.5f + (i % 8);
        worm[i].origin = i;
        worm[i].liberties = 2 + (i % 4);
        worm[i].liberties2 = 1 + (i % 3);
        worm[i].liberties3 = 1 + (i % 2);
        worm[i].liberties4 = 1;
        worm[i].lunch = 0;
        worm[i].cutstone = 0;
        worm[i].cutstone2 = 0;
        worm[i].genus = 1;
        worm[i].inessential = 0;
        worm[i].invincible = 0;
        worm[i].unconditional_status = 1;

        for (int j = 0; j < 10; j++) {
            worm[i].attack_points[j] = 0;
            worm[i].attack_codes[j] = (j == 0) ? ((i % 7) ? 1 : 0) : 0;
            worm[i].defense_points[j] = 0;
            worm[i].defense_codes[j] = (j == 0) ? ((i % 5) ? 1 : 0) : 0;
            worm[i].attack_threat_points[j] = 0;
            worm[i].attack_threat_codes[j] = 0;
            worm[i].defense_threat_points[j] = 0;
            worm[i].defense_threat_codes[j] = 0;
        }

        saved_dragons[i] = (i % 6 == 0);
        saved_worms[i] = (i % 5 == 0);
        safe_stones[i] = 0;
    }

    for (int i = 0; i < 421; i++) {
        board[i] = (i % 4 == 0) ? (color) : ((i % 3 == 0) ? (1 + 2 - color) : 0);
    }

    color = 1;
    pos = 0;
}