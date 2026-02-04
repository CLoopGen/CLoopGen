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
int pos;
int other;
int k;

void init_vars() {
    const int BOARD_SIZE = 19;
    const int TOTAL_SIZE = (BOARD_SIZE + 1) * (BOARD_SIZE + 1);
    
    memset(board, 0, sizeof(board));
    memset(worm, 0, sizeof(worm));
    memset(dragon, 0, sizeof(dragon));

    dragon2 = (struct dragon_data2*)calloc(400, sizeof(struct dragon_data2));
    owl = (struct local_owl_data*)calloc(1, sizeof(struct local_owl_data));

    other = 1;

    for (int i = 0; i < 400; i++) {
        dragon[i].id = -1;
        dragon[i].size = i % 100;
        dragon2[i].origin = i;
        dragon2[i].neighbors = i % 5;
        for (int j = 0; j < dragon2[i].neighbors; j++) {
            dragon2[i].adjacent[j] = (i + j + 1) % 400;
        }
    }

    for (int i = 0; i < 400; i++) {
        owl->goal[i] = 0;
        owl->boundary[i] = 0;
        owl->escape_values[i] = 0;
        owl->inessential[i] = 0;
        owl->safe_move_cache[i] = 0;
        owl->my_eye[i].color = 0;
        owl->my_eye[i].origin = i;
        owl->half_eye[i].value = 0.0f;
        owl->half_eye[i].type = 0;
        owl->half_eye[i].num_attacks = 0;
        owl->half_eye[i].num_defends = 0;
    }

    owl->color = 2;
    owl->lunches_are_current = 0;
    owl->restore_from = 0;
    owl->number_in_stack = 0;

    for (int i = 0; i < 10; i++) {
        owl->lunch[i] = 0;
        owl->lunch_attack_code[i] = 0;
        owl->lunch_attack_point[i] = 0;
        owl->lunch_defend_code[i] = 0;
        owl->lunch_defense_point[i] = 0;
    }

    for (int i = 0; i < 400; i++) {
        worm[i].attack_codes[0] = 0;
        worm[i].size = i % 50;
    }

    for (int i = 19 + 2; i < TOTAL_SIZE; i++) {
        if (i % 7 == 0) {
            board[i] = other;
        } else {
            board[i] = 0;
        }
    }
}