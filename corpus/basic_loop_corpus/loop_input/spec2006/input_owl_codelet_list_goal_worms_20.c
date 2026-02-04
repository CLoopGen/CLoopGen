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

struct eye_data {
    int color;
    int esize;
    int msize;
    int origin;
    struct eyevalue value;
    int attack_point;
    int defense_point;
    char marginal;
    char type;
    char neighbors;
    char marginal_neighbors;
    char cut;
};

struct half_eye_data {
    float value;
    char type;
    int num_attacks;
    int attack_point[4];
    int num_defends;
    int defense_point[4];
};

struct local_owl_data {
    char goal[400];
    char boundary[400];
    char escape_values[400];
    int color;
    struct eye_data my_eye[400];
    struct half_eye_data half_eye[400];
    int lunch[10];
    int lunch_attack_code[10];
    int lunch_attack_point[10];
    int lunch_defend_code[10];
    int lunch_defense_point[10];
    char inessential[400];
    int lunches_are_current;
    char safe_move_cache[400];
    int restore_from;
    int number_in_stack;
};

Intersection board[421];
struct worm_data worm[400];
struct dragon_data dragon[400];
struct dragon_data2 *dragon2;
struct local_owl_data *owl;
int goal_worm[15];
int pos = 0;
int k = 0;
int w = 0;

void init_vars() {
    dragon2 = (struct dragon_data2*)malloc(400 * sizeof(struct dragon_data2));
    owl = (struct local_owl_data*)malloc(sizeof(struct local_owl_data));

    for (int i = 0; i < 421; i++) {
        board[i] = (i < 400) ? 1 : 0;
    }

    for (int i = 0; i < 400; i++) {
        worm[i].color = 1;
        worm[i].size = (i % 5) + 1;
        worm[i].origin = i;
        worm[i].effective_size = 1.0f;
        worm[i].liberties = 2;
        worm[i].lunch = 0;
        worm[i].inessential = 0;
        worm[i].invincible = 0;
        worm[i].unconditional_status = 0;

        dragon[i].color = (i % 2) ? 1 : 2;
        dragon[i].id = i;
        dragon[i].origin = i;
        dragon[i].size = 5;
        dragon[i].effective_size = 3.5f;
        dragon[i].owl_status = 1;
        dragon[i].status = 1;

        dragon2[i].origin = i;
        dragon2[i].neighbors = (i < 100) ? 5 : 0;
        for (int j = 0; j < 10; j++) {
            dragon2[i].adjacent[j] = (j + i) % 400;
        }
        dragon2[i].moyo_territorial_value = 1.5f;
        dragon2[i].weakness = 0.5f;
        dragon2[i].weakness_pre_owl = 0.6f;
        dragon2[i].genus.a = 1;
        dragon2[i].genus.b = 1;
        dragon2[i].heye = 0;
        dragon2[i].semeai = 0;
    }

    owl->color = 1;
    for (int i = 0; i < 400; i++) {
        owl->goal[i] = 0;
        owl->boundary[i] = 0;
        owl->escape_values[i] = 0;
        owl->my_eye[i].color = 1;
        owl->my_eye[i].origin = i;
        owl->my_eye[i].value.a = 1;
        owl->half_eye[i].value = 0.5f;
        owl->inessential[i] = 0;
        owl->safe_move_cache[i] = 0;
    }
    for (int i = 0; i < 10; i++) {
        owl->lunch[i] = 0;
        owl->lunch_attack_code[i] = 0;
        owl->lunch_attack_point[i] = 0;
        owl->lunch_defend_code[i] = 0;
        owl->lunch_defense_point[i] = 0;
    }
    owl->lunches_are_current = 1;
    owl->restore_from = 0;
    owl->number_in_stack = 0;

    pos = 50;
    w = 0;
}