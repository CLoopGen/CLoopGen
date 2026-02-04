#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

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
int color;
char safe_stones[400];
int ii;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i >= 21 && i < 400) ? (i % 3 + 1) : 0;
    }

    for (int i = 0; i < 400; i++) {
        worm[i].color = i % 3;
        worm[i].size = i % 15 + 1;
        worm[i].effective_size = (float)(i % 20);
        worm[i].origin = i;
        worm[i].liberties = i % 5;
        worm[i].liberties2 = i % 6;
        worm[i].liberties3 = i % 7;
        worm[i].liberties4 = i % 8;
        worm[i].lunch = i % 2;
        worm[i].cutstone = i % 3;
        worm[i].cutstone2 = i % 3;
        worm[i].genus = i % 4;
        worm[i].inessential = (i % 7 == 0);
        worm[i].invincible = i % 2;
        worm[i].unconditional_status = i % 4;
        for (int j = 0; j < 10; j++) {
            worm[i].attack_points[j] = (i + j) % 400;
            worm[i].attack_codes[j] = j % 4;
            worm[i].defense_points[j] = (i + j) % 400;
            worm[i].defense_codes[j] = j % 4;
            worm[i].attack_threat_points[j] = (i + j) % 400;
            worm[i].attack_threat_codes[j] = j % 4;
            worm[i].defense_threat_points[j] = (i + j) % 400;
            worm[i].defense_threat_codes[j] = j % 4;
        }
    }

    for (int i = 0; i < 400; i++) {
        dragon[i].color = i % 3;
        dragon[i].id = i % 400;
        dragon[i].origin = i;
        dragon[i].size = i % 20 + 1;
        dragon[i].effective_size = (float)(i % 25);
        dragon[i].crude_status = i % 4;
        dragon[i].owl_threat_status = i % 3;
        dragon[i].owl_status = i % 4;
        dragon[i].owl_attack_point = (i + 1) % 400;
        dragon[i].owl_attack_code = i % 4;
        dragon[i].owl_attack_certain = i % 2;
        dragon[i].owl_second_attack_point = (i + 2) % 400;
        dragon[i].owl_defense_point = (i + 3) % 400;
        dragon[i].owl_defense_code = i % 4;
        dragon[i].owl_defense_certain = i % 2;
        dragon[i].owl_second_defense_point = (i + 4) % 400;
        dragon[i].status = i % 4;
        dragon[i].owl_attack_kworm = (i + 5) % 400;
        dragon[i].owl_defense_kworm = (i + 6) % 400;
    }

    dragon2 = (struct dragon_data2 *)calloc(400, sizeof(struct dragon_data2));
    if (!dragon2) exit(1);

    for (int i = 0; i < 400; i++) {
        dragon2[i].origin = i;
        for (int j = 0; j < 10; j++) {
            dragon2[i].adjacent[j] = (i + j + 1) % 400;
        }
        dragon2[i].neighbors = i % 11;
        dragon2[i].hostile_neighbors = i % 5;
        dragon2[i].moyo_size = i % 50;
        dragon2[i].moyo_territorial_value = (float)(i % 30);
        dragon2[i].safety = i % 7;  // Ensure values 0-6 to cover all cases
        dragon2[i].weakness = (float)(i % 100) / 10.0f;
        dragon2[i].weakness_pre_owl = (float)(i % 100) / 10.0f;
        dragon2[i].escape_route = i % 6;
        dragon2[i].genus.a = i % 4;
        dragon2[i].genus.b = i % 4;
        dragon2[i].genus.c = i % 4;
        dragon2[i].genus.d = i % 4;
        dragon2[i].heye = i % 5;
        dragon2[i].lunch = i % 3;
        dragon2[i].semeai = i % 4;
        dragon2[i].semeai_margin_of_safety = i % 10;
        dragon2[i].surround_status = i % 4;
        dragon2[i].surround_size = i % 20;
    }

    color = 1;
    for (int i = 0; i < 400; i++) {
        safe_stones[i] = 0;
    }
    ii = 0;
}