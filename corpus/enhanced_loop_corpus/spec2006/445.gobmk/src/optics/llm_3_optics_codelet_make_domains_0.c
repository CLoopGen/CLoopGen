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
    int stride = (19 + 1);
    for (i = 0; i < board_size; i++) {
        int base_offset = (19 + 2) + i * stride;
        for (j = 0; j < board_size; j++) {
            pos = base_offset + j;
            if (board[pos] == 0 || !lively[pos]) {
                if (black_domain[pos] == 0 && white_domain[pos] == 0) {
                    if (w_eye)
                        w_eye[pos].color = 3;
                    if (b_eye)
                        b_eye[pos].color = 3;
                } else if (black_domain[pos] == 1 && white_domain[pos] == 0 && b_eye) {
                    b_eye[pos].color = 5;
                    int found = 0;
                    for (k = 0; k < 4 && !found; k++) {
                        int apos = pos + delta[k];
                        if ((board[apos] != 3) && white_domain[apos] && !black_domain[apos]) {
                            b_eye[pos].marginal = 1;
                            found = 1;
                        }
                    }
                } else if (black_domain[pos] == 0 && white_domain[pos] == 1 && w_eye) {
                    w_eye[pos].color = 4;
                    int found = 0;
                    for (k = 0; k < 4 && !found; k++) {
                        int apos = pos + delta[k];
                        if ((board[apos] != 3) && black_domain[apos] && !white_domain[apos]) {
                            w_eye[pos].marginal = 1;
                            found = 1;
                        }
                    }
                } else if (black_domain[pos] == 1 && white_domain[pos] == 1) {
                    if (b_eye) {
                        int found = 0;
                        for (k = 0; k < 4 && !found; k++) {
                            int apos = pos + delta[k];
                            if ((board[apos] != 3) && black_domain[apos] && !white_domain[apos]) {
                                b_eye[pos].marginal = 1;
                                b_eye[pos].color = 5;
                                found = 1;
                            }
                        }
                        if (!found)
                            b_eye[pos].color = 3;
                    }
                    if (w_eye) {
                        int found = 0;
                        for (k = 0; k < 4 && !found; k++) {
                            int apos = pos + delta[k];
                            if ((board[apos] != 3) && white_domain[apos] && !black_domain[apos]) {
                                w_eye[pos].marginal = 1;
                                w_eye[pos].color = 4;
                                found = 1;
                            }
                        }
                        if (!found)
                            w_eye[pos].color = 3;
                    }
                }
            }
        }
    }
}
