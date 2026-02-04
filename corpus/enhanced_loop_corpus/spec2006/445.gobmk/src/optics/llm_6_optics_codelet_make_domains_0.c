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
for (i = 0; i < board_size; i++)
    for (j = 0; j < board_size; j++) {
        pos = ((19 + 2) + (i) * (19 + 1) + (j));
        if (board[pos] == 0 || !lively[pos]) {
            int bd = black_domain[pos];
            int wd = white_domain[pos];
            if (bd == 0 && wd == 0) {
                if (w_eye)
                    w_eye[pos].color = 3;
                if (b_eye)
                    b_eye[pos].color = 3;
            } else if (bd == 1 && wd == 0 && b_eye) {
                b_eye[pos].color = 5;
                int found_marginal = 0;
                for (k = 0; k < 4 && !found_marginal; k++) {
                    int apos = pos + delta[k];
                    if ((board[apos] != 3) && white_domain[apos] && !black_domain[apos]) {
                        b_eye[pos].marginal = 1;
                        found_marginal = 1;
                    }
                }
            } else if (bd == 0 && wd == 1 && w_eye) {
                w_eye[pos].color = 4;
                int found_marginal = 0;
                for (k = 0; k < 4 && !found_marginal; k++) {
                    int apos = pos + delta[k];
                    if ((board[apos] != 3) && black_domain[apos] && !white_domain[apos]) {
                        w_eye[pos].marginal = 1;
                        found_marginal = 1;
                    }
                }
            } else if (bd == 1 && wd == 1) {
                if (b_eye) {
                    int found_b = 0;
                    for (k = 0; k < 4 && !found_b; k++) {
                        int apos = pos + delta[k];
                        if ((board[apos] != 3) && black_domain[apos] && !white_domain[apos]) {
                            b_eye[pos].marginal = 1;
                            b_eye[pos].color = 5;
                            found_b = 1;
                        }
                    }
                    if (!found_b)
                        b_eye[pos].color = 3;
                }
                if (w_eye) {
                    int found_w = 0;
                    for (k = 0; k < 4 && !found_w; k++) {
                        int apos = pos + delta[k];
                        if ((board[apos] != 3) && white_domain[apos] && !black_domain[apos]) {
                            w_eye[pos].marginal = 1;
                            w_eye[pos].color = 4;
                            found_w = 1;
                        }
                    }
                    if (!found_w)
                        w_eye[pos].color = 3;
                }
            }
        }
    }
}
