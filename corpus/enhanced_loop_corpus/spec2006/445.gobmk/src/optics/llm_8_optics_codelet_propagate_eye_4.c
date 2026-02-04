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
    int start = 21;
    int end = 361;
    for (pos = start; pos < end; pos += 2) {
        if ((board[pos] != 3) && eye[pos].origin == origin) {
            eye[pos].color = eye[origin].color;
            eye[pos].esize = eye[origin].esize;
            eye[pos].msize = eye[origin].msize;
            eye[pos].origin = eye[origin].origin;
            eye[pos].value.a = eye[origin].value.a;
            eye[pos].value.b = eye[origin].value.b;
            eye[pos].value.c = eye[origin].value.c;
            eye[pos].value.d = eye[origin].value.d;
            eye[pos].attack_point = eye[origin].attack_point;
            eye[pos].defense_point = eye[origin].defense_point;
        }
    }
}
