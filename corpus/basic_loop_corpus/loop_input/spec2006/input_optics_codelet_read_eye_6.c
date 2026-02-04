#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

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

Intersection board[421];
int pos = 100;
struct eye_data eye[400];
struct half_eye_data heye[400];
int pos2;
int ko_halfeye;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 3 == 0) ? 3 : 2;
    }

    for (int i = 0; i < 400; i++) {
        eye[i].origin = (i % 17);
        heye[i].type = (i % 3 == 0) ? 2 : 1;
        heye[i].value = (i % 5 == 0) ? 2.5f : 3.5f;
    }

    pos = 5;
    ko_halfeye = 1;
}