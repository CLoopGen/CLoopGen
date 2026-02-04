#include <stdio.h>
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

typedef unsigned char Intersection;

struct eye_data eyedata[400];
int pos;
int k;
int delta[8] = {1, -1, 19 + 1, -(19 + 1)};
Intersection board[421];

void init_vars() {
    for (int i = 0; i < 400; i++) {
        eyedata[i].color = i % 3;
        eyedata[i].esize = 1;
        eyedata[i].msize = 1;
        eyedata[i].origin = (i == 100 || i == 200) ? 0 : (i % 50 != 0 ? (i % 50) : i);
        eyedata[i].value.a = 1;
        eyedata[i].value.b = 2;
        eyedata[i].value.c = 3;
        eyedata[i].value.d = 4;
        eyedata[i].attack_point = i * 3;
        eyedata[i].defense_point = i * 2;
        eyedata[i].marginal = (i % 7 == 0);
        eyedata[i].type = 'A';
        eyedata[i].neighbors = 0;
        eyedata[i].marginal_neighbors = 0;
        eyedata[i].cut = 0;
    }

    for (int i = 0; i < 421; i++) {
        board[i] = (i >= 21 && i < 400 + 21) ? ((i % 13 == 0) ? 1 : 3) : 0;
    }

    pos = 0;
    k = 0;
}