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

int board_size = 19;
struct eye_data eye[400];
int m;
int n;
int mini = 1000;
int maxi = -1;
int minj = 1000;
int maxj = -1;
int origin = 5;

void init_vars() {
    for (int i = 0; i < 400; i++) {
        eye[i].color = i * 37 % 100;
        eye[i].esize = i * 13 % 8;
        eye[i].msize = i * 17 % 6;
        eye[i].origin = (i == 20 || i == 50 || i == 100 || i == 200 || i == 300) ? origin : origin - 1;
        eye[i].value.a = i % 255;
        eye[i].value.b = (i + 1) % 255;
        eye[i].value.c = (i + 2) % 255;
        eye[i].value.d = (i + 3) % 255;
        eye[i].attack_point = i * 7 % 20;
        eye[i].defense_point = i * 11 % 25;
        eye[i].marginal = (i % 2 == 0) ? 1 : 0;
        eye[i].type = i % 4;
        eye[i].neighbors = i % 8;
        eye[i].marginal_neighbors = i % 5;
        eye[i].cut = (i % 10 == 0) ? 1 : 0;
    }
    board_size = 19;
    mini = 1000;
    maxi = -1;
    minj = 1000;
    maxj = -1;
    origin = 5;
    m = 0;
    n = 0;
}