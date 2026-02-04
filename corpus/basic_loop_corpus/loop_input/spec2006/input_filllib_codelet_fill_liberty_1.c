#include <stdio.h>
#include <stdlib.h>
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

int delta[8] = { -21, -19, -1, 1, 21, 19, -20, 20 };
Intersection board[421];
struct worm_data worm[400];
struct dragon_data dragon[400];
struct dragon_data2 *dragon2;
int k;
int pos;
int potential_color[400];

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= 21 && i < 400) ? (i % 3) + 1 : 0;
    }
    for (int i = 0; i < 400; i++) {
        worm[i].inessential = (i % 7) == 0;
        dragon[i].id = i % 400;
        dragon[i].status = i % 3;
        dragon[i].color = (i % 2) + 1;
        potential_color[i] = 0;
    }
    dragon2 = (struct dragon_data2*)calloc(400, sizeof(struct dragon_data2));
    for (int i = 0; i < 400; i++) {
        dragon2[i].safety = (i % 6);
    }
}