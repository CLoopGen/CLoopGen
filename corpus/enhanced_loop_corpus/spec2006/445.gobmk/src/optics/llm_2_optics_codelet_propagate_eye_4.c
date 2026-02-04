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
    // Variant 1: Consecutive memory access by precomputing base pointer and iterating with offset
    struct eye_data *eye_origin_ptr = &eye[origin];
    int base = (19 + 2);
    int limit = (19 + 1) * (19 + 1);
    for (int idx = 0; idx < limit - base; idx++) {
        int pos = base + idx;
        if ((board[pos] != 3) && eye[pos].origin == origin) {
            struct eye_data *dst = &eye[pos];
            dst->color = eye_origin_ptr->color;
            dst->esize = eye_origin_ptr->esize;
            dst->msize = eye_origin_ptr->msize;
            dst->origin = eye_origin_ptr->origin;
            dst->value = eye_origin_ptr->value;
            dst->attack_point = eye_origin_ptr->attack_point;
            dst->defense_point = eye_origin_ptr->defense_point;
        }
    }
}
