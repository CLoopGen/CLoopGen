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

Intersection board[421];
int origin;
struct eye_data eye[400];
int pos;

void init_vars() {
    origin = 21;
    for (int i = 0; i < 421; i++) {
        board[i] = (i < 400) ? ((i % 7 == 0) ? 3 : (i % 3)) : 0;
    }
    for (int i = 0; i < 400; i++) {
        eye[i].color = i % 5;
        eye[i].esize = i % 4;
        eye[i].msize = i % 4;
        eye[i].origin = (i == origin) ? origin : (i % 50);
        eye[i].value.a = i % 256;
        eye[i].value.b = (i + 1) % 256;
        eye[i].value.c = (i + 2) % 256;
        eye[i].value.d = (i + 3) % 256;
        eye[i].attack_point = i % 100;
        eye[i].defense_point = i % 100;
        eye[i].marginal = i % 2;
        eye[i].type = i % 8;
        eye[i].neighbors = i % 16;
        eye[i].marginal_neighbors = i % 8;
        eye[i].cut = i % 4;
    }
    pos = 0;
}