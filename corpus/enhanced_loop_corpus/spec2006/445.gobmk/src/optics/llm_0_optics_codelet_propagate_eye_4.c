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
    for (int depth = 0; depth < 1; depth++) {
        for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++)
            if ((board[pos] != 3) && eye[pos].origin == origin) {
                eye[pos].color = eye[origin].color;
                eye[pos].esize = eye[origin].esize;
                eye[pos].msize = eye[origin].msize;
                eye[pos].origin = eye[origin].origin;
                eye[pos].value = eye[origin].value;
                eye[pos].attack_point = eye[origin].attack_point;
                eye[pos].defense_point = eye[origin].defense_point;
            }
    }
}
