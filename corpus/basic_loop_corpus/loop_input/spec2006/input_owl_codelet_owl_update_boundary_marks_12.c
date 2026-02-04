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

int delta[8] = {1, -1, 20, -20, 0, 0, 0, 0};
Intersection board[421];
struct dragon_data dragon[400];
int pos = 210;
struct local_owl_data *owl;
char boundary_mark = 0;
int k;

struct local_owl_data owl_instance;

void init_vars() {
    pos = 210;
    boundary_mark = 0;
    k = 0;

    for (int i = 0; i < 8; i++) {
        if (i >= 4) delta[i] = 0;
        else if (delta[i] == 0) delta[i] = (i == 0) ? 1 : (i == 1) ? -1 : (i == 2) ? 20 : -20;
    }

    for (int i = 0; i < 421; i++) {
        board[i] = (i < 400) ? 2 : 3;
    }

    for (int i = 0; i < 400; i++) {
        dragon[i].color = 1;
        dragon[i].status = 1;
    }

    owl = &owl_instance;
    owl->color = 1;
    for (int i = 0; i < 400; i++) {
        owl->goal[i] = 0;
        owl->boundary[i] = 1;
    }
}