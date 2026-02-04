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


extern int delta[8];
extern int board_size;
extern Intersection board[421];
extern int black_domain[400];
extern int white_domain[400];
extern struct eye_data b_eye[400];
extern struct eye_data w_eye[400];
extern int i;
extern int j;
extern int k;
extern int pos;
extern int lively[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp_color_b[400] = {0};
int temp_marginal_b[400] = {0};
int temp_color_w[400] = {0};
int temp_marginal_w[400] = {0};

for (i = 0; i < board_size; i++)
    for (j = 0; j < board_size; j++) {
        pos = ((19 + 2) + (i) * (19 + 1) + (j));
        if (board[pos] == 0 || !lively[pos]) {
            int bd = black_domain[pos];
            int wd = white_domain[pos];
            if (bd == 0 && wd == 0) {
                temp_color_b[pos] = 3;
                temp_color_w[pos] = 3;
            } else if (bd == 1 && wd == 0) {
                temp_color_b[pos] = 5;
                for (k = 0; k < 4; k++) {
                    int apos = pos + delta[k];
                    if ((board[apos] != 3) && white_domain[apos] && !black_domain[apos]) {
                        temp_marginal_b[pos] = 1;
                        break;
                    }
                }
            } else if (bd == 0 && wd == 1) {
                temp_color_w[pos] = 4;
                for (k = 0; k < 4; k++) {
                    int apos = pos + delta[k];
                    if ((board[apos] != 3) && black_domain[apos] && !white_domain[apos]) {
                        temp_marginal_w[pos] = 1;
                        break;
                    }
                }
            } else if (bd == 1 && wd == 1) {
                for (k = 0; k < 4; k++) {
                    int apos = pos + delta[k];
                    if ((board[apos] != 3) && black_domain[apos] && !white_domain[apos]) {
                        temp_marginal_b[pos] = 1;
                        temp_color_b[pos] = 5;
                        break;
                    }
                }
                if (k == 4)
                    temp_color_b[pos] = 3;
                for (k = 0; k < 4; k++) {
                    int apos = pos + delta[k];
                    if ((board[apos] != 3) && white_domain[apos] && !black_domain[apos]) {
                        temp_marginal_w[pos] = 1;
                        temp_color_w[pos] = 4;
                        break;
                    }
                }
                if (k == 4)
                    temp_color_w[pos] = 3;
            }
        }
    }

for (i = 0; i < board_size; i++)
    for (j = 0; j < board_size; j++) {
        pos = ((19 + 2) + (i) * (19 + 1) + (j));
        if (b_eye) {
            b_eye[pos].color = temp_color_b[pos];
            b_eye[pos].marginal = temp_marginal_b[pos];
        }
        if (w_eye) {
            w_eye[pos].color = temp_color_w[pos];
            w_eye[pos].marginal = temp_marginal_w[pos];
        }
    }
}
