#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

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

int board_size = 19;
int m;
int n;

struct local_owl_data *owl;

void init_vars() {
    owl = (struct local_owl_data *)calloc(1, sizeof(struct local_owl_data));
    if (!owl) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}