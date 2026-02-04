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
extern Intersection board[421];
extern int pos;
extern struct eye_data eye[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    struct eye_data *eye_local[4];
    int indices[4];
    int count = 0;

    for (k = 0; k < 4; k++) {
        int idx = pos + delta[k];
        if ((board[idx] != 3) && eye[idx].origin == eye[pos].origin) {
            indices[count] = idx;
            eye_local[count] = &eye[idx];
            count++;
        }
    }

    for (k = 0; k < count; k++) {
        eye_local[k]->marginal_neighbors++;
    }
}
