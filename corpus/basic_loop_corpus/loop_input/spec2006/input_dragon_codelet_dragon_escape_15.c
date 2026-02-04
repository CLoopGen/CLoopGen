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
struct eye_data white_eye[400];
struct eye_data black_eye[400];
int color;
char escape_value[400];
int ii;
int mx[400];
int queue[361];
int queue_start;
int queue_end;
int other;
int distance;
int escape_potential;

void init_vars() {
    color = 1;
    other = 2;
    queue_start = 0;
    queue_end = 0;
    escape_potential = 0;

    for (int i = 0; i < 421; i++) {
        if (i < 400) {
            mx[i] = 0;
            escape_value[i] = 1;
            white_eye[i].type = 0;
            white_eye[i].cut = 0;
            black_eye[i].type = 0;
            black_eye[i].cut = 0;
            if (i < 361) {
                queue[i] = i % 400;
            }
        }
        if (i < 400) {
            board[i] = (i % 5 == 0) ? 3 : ((i % 4 == 0) ? color : 0);
        } else {
            board[i] = 3;
        }
    }

    for (int i = 0; i < 400; i++) {
        white_eye[i].color = 1;
        black_eye[i].color = 2;
    }

    queue_end = 360;
}