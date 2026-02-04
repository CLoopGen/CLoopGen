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


struct half_eye_data {
    float value;
    char type;
    int num_attacks;
    int attack_point[4];
    int num_defends;
    int defense_point[4];
};


struct local_owl_data {
    char goal[400];
    char boundary[400];
    char escape_values[400];
    int color;
    struct eye_data my_eye[400];
    struct half_eye_data half_eye[400];
    int lunch[10];
    int lunch_attack_code[10];
    int lunch_attack_point[10];
    int lunch_defend_code[10];
    int lunch_defense_point[10];
    char inessential[400];
    int lunches_are_current;
    char safe_move_cache[400];
    int restore_from;
    int number_in_stack;
};


extern int delta[8];
extern int board_size;
extern Intersection board[421];
extern struct local_owl_data *owl;
extern int color;
extern struct eye_data *eye;
extern char mw[400];
extern char mz[400];
extern int m;
extern int n;
extern int k;
extern int eye_color;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (m = 0; m < board_size; m++) {
        for (n = 0; n < board_size; n++) {
            int pos = ((19 + 2) + (m) * (19 + 1) + (n));
            if (board[pos] == color) {
                int pos2;
                for (k = 0; k < 4; k++) {
                    pos2 = pos + delta[k];
                    if ((board[pos2] != 3) && eye[pos2].color == eye_color && eye[pos2].origin != 0 && !eye[pos2].marginal) {
                        if (owl->goal[pos])
                            mw[eye[pos2].origin]++;
                        else
                            mz[eye[pos2].origin]++;
                    }
                }
                for (k = 4; k < 8; k++) {
                    pos2 = pos + delta[k];
                    if ((board[pos2] != 3) && eye[pos2].color == eye_color && eye[pos2].origin != 0 && !eye[pos2].marginal) {
                        if (owl->goal[pos])
                            mw[eye[pos2].origin]++;
                        else
                            mz[eye[pos2].origin]++;
                    }
                }
            }
        }
    }
}
