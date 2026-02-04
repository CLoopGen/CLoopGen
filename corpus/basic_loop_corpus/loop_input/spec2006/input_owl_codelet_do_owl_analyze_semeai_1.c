#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

struct eyevalue {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
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

struct local_owl_data *owla;
struct local_owl_data *owlb;
int k;

void init_vars() {
    owla = (struct local_owl_data *)calloc(1, sizeof(struct local_owl_data));
    owlb = (struct local_owl_data *)calloc(1, sizeof(struct local_owl_data));

    if (!owla || !owlb) {
        exit(1);
    }

    for (int i = 0; i < 10; i++) {
        owla->lunch[i] = (i < 5) ? (399 - i * 40) : 0;
        owla->lunch_attack_code[i] = i + 1;
        owla->lunch_attack_point[i] = i * 2;
        owla->lunch_defend_code[i] = i + 5;
        owla->lunch_defense_point[i] = i * 3;
    }

    for (int i = 0; i < 400; i++) {
        owlb->goal[i] = (i % 7 == 0) ? 1 : 0;
        owlb->boundary[i] = i % 2;
        owlb->escape_values[i] = i % 3;
        owlb->inessential[i] = i % 5;
        owlb->safe_move_cache[i] = i % 2;

        owla->my_eye[i].color = i % 2;
        owla->my_eye[i].esize = i % 10;
        owla->my_eye[i].msize = i % 8;
        owla->my_eye[i].origin = i % 100;
        owla->my_eye[i].value.a = i % 256;
        owla->my_eye[i].value.b = (i + 1) % 256;
        owla->my_eye[i].value.c = (i + 2) % 256;
        owla->my_eye[i].value.d = (i + 3) % 256;
        owla->my_eye[i].attack_point = i * 2;
        owla->my_eye[i].defense_point = i * 3;
        owla->my_eye[i].marginal = i % 2;
        owla->my_eye[i].type = i % 4;
        owla->my_eye[i].neighbors = i % 8;
        owla->my_eye[i].marginal_neighbors = i % 4;
        owla->my_eye[i].cut = i % 2;

        owla->half_eye[i].value = i * 0.5f;
        owla->half_eye[i].type = i % 3;
        owla->half_eye[i].num_attacks = i % 5;
        owla->half_eye[i].num_defends = i % 5;
        for (int j = 0; j < 4; j++) {
            owla->half_eye[i].attack_point[j] = (i + j) % 400;
            owla->half_eye[i].defense_point[j] = (i + j + 10) % 400;
        }
    }

    owla->color = 1;
    owla->lunches_are_current = 1;
    owla->restore_from = 0;
    owla->number_in_stack = 5;

    owlb->color = 2;
    owlb->lunches_are_current = 0;
    owlb->restore_from = 10;
    owlb->number_in_stack = 8;
}