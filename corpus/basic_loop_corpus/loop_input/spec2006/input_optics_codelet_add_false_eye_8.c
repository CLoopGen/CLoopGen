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

int delta[8] = {1, 41, -1, -41, 2, 82, -2, -82};

#define BOARD_SIZE 421
#define EYE_SIZE 400

Intersection board[BOARD_SIZE];
struct eye_data eye[EYE_SIZE];
int pos = 200; // ensure within bounds for all delta[k] accesses
int k = 0;

void init_vars() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (i % 7 == 0) ? 3 : 2;
    }

    for (int i = 0; i < EYE_SIZE; i++) {
        eye[i].color = i % 3;
        eye[i].esize = (i * 7) % 5;
        eye[i].msize = (i * 11) % 6;
        eye[i].origin = (i >= 190 && i <= 210) ? 100 : i - 50;
        eye[i].value.a = i % 255;
        eye[i].value.b = (i + 10) % 255;
        eye[i].value.c = (i + 20) % 255;
        eye[i].value.d = (i + 30) % 255;
        eye[i].attack_point = i % 100;
        eye[i].defense_point = i % 120;
        eye[i].marginal = (i % 13) == 0;
        eye[i].type = i % 4;
        eye[i].neighbors = i % 8;
        eye[i].marginal_neighbors = 0;
        eye[i].cut = (i % 17) == 0;
    }

    pos = 200;
}