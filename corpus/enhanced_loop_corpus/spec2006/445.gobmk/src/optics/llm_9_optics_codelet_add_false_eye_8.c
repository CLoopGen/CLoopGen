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
    for (k = 0; k < 4; k += 2) {
        int d1 = delta[k];
        int d2 = (k + 1 < 4) ? delta[k + 1] : d1;
        int pos1 = pos + d1;
        int pos2 = pos + d2;

        if ((board[pos1] != 3) && eye[pos1].origin == eye[pos].origin)
            eye[pos1].marginal_neighbors++;

        if ((k + 1 < 4) && (board[pos2] != 3) && eye[pos2].origin == eye[pos].origin)
            eye[pos2].marginal_neighbors++;
    }
}
