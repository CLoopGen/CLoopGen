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
for (i = 0; i < board_size * board_size; i++) {
    j = i % board_size;
    int temp_pos = ((19 + 2) + (i / board_size) * (19 + 1) + j);
    if (board[temp_pos] == 0 || !lively[temp_pos]) {
        if (black_domain[temp_pos] == 0 && white_domain[temp_pos] == 0) {
            if (w_eye)
                w_eye[temp_pos].color = 3;
            if (b_eye)
                b_eye[temp_pos].color = 3;
        } else if (black_domain[temp_pos] == 1 && white_domain[temp_pos] == 0 && b_eye) {
            b_eye[temp_pos].color = 5;
            int found_marginal = 0;
            for (k = 0; k < 8 && !found_marginal; k++) {
                int apos = temp_pos + delta[k];
                if ((board[apos] != 3) && white_domain[apos] && !black_domain[apos]) {
                    b_eye[temp_pos].marginal = 1;
                    found_marginal = 1;
                }
            }
        } else if (black_domain[temp_pos] == 0 && white_domain[temp_pos] == 1 && w_eye) {
            w_eye[temp_pos].color = 4;
            int found_marginal = 0;
            for (k = 0; k < 8 && !found_marginal; k++) {
                int apos = temp_pos + delta[k];
                if ((board[apos] != 3) && black_domain[apos] && !white_domain[apos]) {
                    w_eye[temp_pos].marginal = 1;
                    found_marginal = 1;
                }
            }
        } else if (black_domain[temp_pos] == 1 && white_domain[temp_pos] == 1) {
            if (b_eye) {
                int found_marginal_b = 0;
                for (k = 0; k < 8 && !found_marginal_b; k++) {
                    int apos = temp_pos + delta[k];
                    if ((board[apos] != 3) && black_domain[apos] && !white_domain[apos]) {
                        b_eye[temp_pos].marginal = 1;
                        b_eye[temp_pos].color = 5;
                        found_marginal_b = 1;
                    }
                }
                if (!found_marginal_b)
                    b_eye[temp_pos].color = 3;
            }
            if (w_eye) {
                int found_marginal_w = 0;
                for (k = 0; k < 8 && !found_marginal_w; k++) {
                    int apos = temp_pos + delta[k];
                    if ((board[apos] != 3) && white_domain[apos] && !black_domain[apos]) {
                        w_eye[temp_pos].marginal = 1;
                        w_eye[temp_pos].color = 4;
                        found_marginal_w = 1;
                    }
                }
                if (!found_marginal_w)
                    w_eye[temp_pos].color = 3;
            }
        }
    }
}
}
