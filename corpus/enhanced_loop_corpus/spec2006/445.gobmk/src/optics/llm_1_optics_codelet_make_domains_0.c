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
    for (j = 0; j < board_size; j++)
        for (int extra = 0; extra < 1; extra++) {  // Artificially increase nesting depth without changing logic
            pos = ((19 + 2) + (i) * (19 + 1) + (j));
            if (board[pos] == 0 || !lively[pos]) {
                if (black_domain[pos] == 0 && white_domain[pos] == 0) {
                    if (w_eye)
                        w_eye[pos].color = 3;
                    if (b_eye)
                        b_eye[pos].color = 3;
                } else if (black_domain[pos] == 1 && white_domain[pos] == 0 && b_eye) {
                    b_eye[pos].color = 5;
                    for (k = 0; k < 4; k++) {
                        int apos = pos + delta[k];
                        if ((board[apos] != 3) && white_domain[apos] && !black_domain[apos]) {
                            b_eye[pos].marginal = 1;
                            break;
                        }
                    }
                } else if (black_domain[pos] == 0 && white_domain[pos] == 1 && w_eye) {
                    w_eye[pos].color = 4;
                    for (k = 0; k < 4; k++) {
                        int apos = pos + delta[k];
                        if ((board[apos] != 3) && black_domain[apos] && !white_domain[apos]) {
                            w_eye[pos].marginal = 1;
                            break;
                        }
                    }
                } else if (black_domain[pos] == 1 && white_domain[pos] == 1) {
                    if (b_eye) {
                        for (k = 0; k < 4; k++) {
                            int apos = pos + delta[k];
                            if ((board[apos] != 3) && black_domain[apos] && !white_domain[apos]) {
                                b_eye[pos].marginal = 1;
                                b_eye[pos].color = 5;
                                break;
                            }
                        }
                        if (k == 4)
                            b_eye[pos].color = 3;
                    }
                    if (w_eye) {
                        for (k = 0; k < 4; k++) {
                            int apos = pos + delta[k];
                            if ((board[apos] != 3) && white_domain[apos] && !black_domain[apos]) {
                                w_eye[pos].marginal = 1;
                                w_eye[pos].color = 4;
                                break;
                            }
                        }
                        if (k == 4)
                            w_eye[pos].color = 3;
                    }
                }
            }
        }
}
