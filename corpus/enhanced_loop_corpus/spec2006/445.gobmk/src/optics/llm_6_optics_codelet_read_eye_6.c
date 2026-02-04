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


extern Intersection board[421];
extern int pos;
extern struct eye_data eye[400];
extern struct half_eye_data heye[400];
extern int pos2;
extern int ko_halfeye;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_ko_halfeye = 0;
    for (pos2 = (19 + 2); pos2 < (19 + 1) * (19 + 1); pos2++) {
        if ((board[pos2] != 3) && eye[pos2].origin == pos && heye[pos2].type == 2 && heye[pos2].value < 3.) {
            if (temp_ko_halfeye == 0) {
                temp_ko_halfeye = pos2;
            } else {
                // Introduce WAW dependency: overwrite only if another valid pos2 is found
                temp_ko_halfeye = pos2; // Eliminates early exit, creates loop-carried WAW on temp_ko_halfeye
            }
        }
    }
    ko_halfeye = temp_ko_halfeye; // Final write to shared variable outside loop (eliminates loop-carried WAR/WAW)
}
