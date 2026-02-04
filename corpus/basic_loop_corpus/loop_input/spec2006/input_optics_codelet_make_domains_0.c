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

int delta[8] = { -21, -1, 21, 1, -20, 20, -19, 19 }; // typical Go board deltas for 19x19 with padding

int board_size = 19;

Intersection board[421];

int black_domain[400];
int white_domain[400];
struct eye_data b_eye[400];
struct eye_data w_eye[400];
int i, j, k, pos;
int lively[400];

void init_vars() {
    for (int idx = 0; idx < 421; ++idx) {
        if (idx < 400) {
            black_domain[idx] = 0;
            white_domain[idx] = 0;
            b_eye[idx].color = 0;
            b_eye[idx].marginal = 0;
            w_eye[idx].color = 0;
            w_eye[idx].marginal = 0;
            lively[idx] = 1;
            b_eye[idx].esize = 0;
            b_eye[idx].msize = 0;
            b_eye[idx].origin = 0;
            b_eye[idx].attack_point = 0;
            b_eye[idx].defense_point = 0;
            b_eye[idx].type = 0;
            b_eye[idx].neighbors = 0;
            b_eye[idx].marginal_neighbors = 0;
            b_eye[idx].cut = 0;
            w_eye[idx].esize = 0;
            w_eye[idx].msize = 0;
            w_eye[idx].origin = 0;
            w_eye[idx].attack_point = 0;
            w_eye[idx].defense_point = 0;
            w_eye[idx].type = 0;
            w_eye[idx].neighbors = 0;
            w_eye[idx].marginal_neighbors = 0;
            w_eye[idx].cut = 0;
            for (int v = 0; v < 4; ++v) {
                b_eye[idx].value.a = 0;
                b_eye[idx].value.b = 0;
                b_eye[idx].value.c = 0;
                b_eye[idx].value.d = 0;
                w_eye[idx].value.a = 0;
                w_eye[idx].value.b = 0;
                w_eye[idx].value.c = 0;
                w_eye[idx].value.d = 0;
            }
        }
        if (idx < 421) {
            board[idx] = 0;
        }
    }

    for (int row = 0; row < 19; ++row) {
        for (int col = 0; col < 19; ++col) {
            int pos_idx = (19 + 2) + row * (19 + 1) + col;
            if (pos_idx >= 421) continue;
            board[pos_idx] = 0;
            int linear = row * 19 + col;
            if (linear < 400) {
                lively[linear] = (row >= 3 && row < 16 && col >= 3 && col < 16) ? 1 : 0;
                black_domain[linear] = 0;
                white_domain[linear] = 0;
            }
        }
    }

    int center_start = 4 * (19 + 1) + 4;
    for (int di = 0; di < 4; ++di) {
        int p = center_start + delta[di];
        if (p >= 0 && p < 421) {
            board[p] = 1;
        }
    }

    for (int idx = 0; idx < 400; ++idx) {
        if (idx % 7 == 0) black_domain[idx] = 1;
        if (idx % 11 == 0) white_domain[idx] = 1;
        if (idx % 77 == 0) {
            black_domain[idx] = 1;
            white_domain[idx] = 1;
        }
    }

    board[center_start] = 3;

    for (int idx = 0; idx < 400; ++idx) {
        lively[idx] = (idx % 13 != 0);
    }
}