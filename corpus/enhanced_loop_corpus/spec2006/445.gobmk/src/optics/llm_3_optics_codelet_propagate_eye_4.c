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
    // Variant 2: Strided memory access — process every 2nd element forward, then handle remainder if needed
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    int stride = 2;

    // First pass: strided access with step size
    for (int p = start; p < end; p += stride) {
        if ((board[p] != 3) && eye[p].origin == origin) {
            eye[p].color = eye[origin].color;
            eye[p].esize = eye[origin].esize;
            eye[p].msize = eye[origin].msize;
            eye[p].origin = eye[origin].origin;
            eye[p].value = eye[origin].value;
            eye[p].attack_point = eye[origin].attack_point;
            eye[p].defense_point = eye[origin].defense_point;
        }
    }

    // Second pass: handle odd-offset elements if stride leaves gaps
    for (int p = start + 1; p < end; p += stride) {
        if ((board[p] != 3) && eye[p].origin == origin) {
            eye[p].color = eye[origin].color;
            eye[p].esize = eye[origin].esize;
            eye[p].msize = eye[origin].msize;
            eye[p].origin = eye[origin].origin;
            eye[p].value = eye[origin].value;
            eye[p].attack_point = eye[origin].attack_point;
            eye[p].defense_point = eye[origin].defense_point;
        }
    }
}
