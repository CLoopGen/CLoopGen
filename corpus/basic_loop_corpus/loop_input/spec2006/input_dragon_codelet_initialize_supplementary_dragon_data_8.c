#include <stdio.h>
#include <stdlib.h>
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
struct dragon_data dragon[400];
struct dragon_data2 *dragon2;
int str;

void init_vars() {
    dragon2 = (struct dragon_data2*)calloc(400, sizeof(struct dragon_data2));
    if (!dragon2) {
        exit(1);
    }

    for (int i = 0; i < 421; i++) {
        board[i] = (i % 4);
    }

    for (int i = 0; i < 400; i++) {
        dragon[i].color = i % 3;
        dragon[i].id = i;
        dragon[i].origin = (i == 0 || i % 19 == 0) ? i : (i % 19);
    }
}