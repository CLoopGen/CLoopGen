#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

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

Intersection board[421];
struct worm_data worm[400];
struct dragon_data dragon[400];
struct dragon_data2 *dragon2;
int pos;
int dragon_status_known;
int ii;
char goal[400];
char escape_value[400];

void init_vars() {
    memset(board, 0, sizeof(board));
    memset(worm, 0, sizeof(worm));
    memset(dragon, 0, sizeof(dragon));
    dragon2 = (struct dragon_data2 *)calloc(400, sizeof(struct dragon_data2));
    memset(goal, 0, sizeof(goal));
    memset(escape_value, 0, sizeof(escape_value));

    pos = 21;
    dragon_status_known = 1;

    for (int i = 0; i < 400; i++) {
        worm[i].attack_codes[0] = (i % 7 == 0) ? 1 : 0;
        dragon[i].crude_status = (i % 5 == 0) ? 1 : ((i % 3 == 0) ? 3 : 2);
        dragon[i].id = i;
        dragon2[i].escape_route = (i % 13 == 0) ? 6 : 3;
        dragon2[i].moyo_size = (i % 17 == 0) ? 6 : 3;
        goal[i] = (i % 11 == 0) ? 1 : 0;
    }

    for (int i = 21; i < 421; i++) {
        board[i] = (i % 4 == 0) ? 3 : 1;
    }
}