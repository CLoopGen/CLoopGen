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


extern Intersection board[421];
extern int origin;
extern struct eye_data eye[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_color, temp_esize, temp_msize, temp_origin_val;
    struct eyevalue temp_value;
    int temp_attack, temp_defense;
    int first_load_done = 0;

    for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
        if ((board[pos] != 3) && eye[pos].origin == origin) {
            if (!first_load_done) {
                temp_color = eye[origin].color;
                temp_esize = eye[origin].esize;
                temp_msize = eye[origin].msize;
                temp_origin_val = eye[origin].origin;
                temp_value = eye[origin].value;
                temp_attack = eye[origin].attack_point;
                temp_defense = eye[origin].defense_point;
                first_load_done = 1;
            }
            eye[pos].color = temp_color;
            eye[pos].esize = temp_esize;
            eye[pos].msize = temp_msize;
            eye[pos].origin = temp_origin_val;
            eye[pos].value = temp_value;
            eye[pos].attack_point = temp_attack;
            eye[pos].defense_point = temp_defense;
        }
    }
}
