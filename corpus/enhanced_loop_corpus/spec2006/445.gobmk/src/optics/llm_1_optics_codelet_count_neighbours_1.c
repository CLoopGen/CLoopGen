#include <stdio.h>

#include <inttypes.h>

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


typedef unsigned char Intersection;

extern struct eye_data eyedata[400];
extern int pos;
extern int k;
extern int delta[8];
extern Intersection board[421];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce loop nesting by unrolling the inner loop manually
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if (!(board[pos] != 3) || eyedata[pos].origin == 0)
        continue;
    eyedata[pos].esize = eyedata[eyedata[pos].origin].esize;
    eyedata[pos].msize = eyedata[eyedata[pos].origin].msize;
    eyedata[pos].neighbors = 0;
    eyedata[pos].marginal_neighbors = 0;

    // Unrolled version of k loop: replacing for(k=0; k<4; k++) with direct access
    int pos2_0 = pos + delta[0];
    if ((board[pos2_0] != 3) && eyedata[pos2_0].origin == eyedata[pos].origin) {
        eyedata[pos].neighbors++;
        if (eyedata[pos2_0].marginal)
            eyedata[pos].marginal_neighbors++;
    }

    int pos2_1 = pos + delta[1];
    if ((board[pos2_1] != 3) && eyedata[pos2_1].origin == eyedata[pos].origin) {
        eyedata[pos].neighbors++;
        if (eyedata[pos2_1].marginal)
            eyedata[pos].marginal_neighbors++;
    }

    int pos2_2 = pos + delta[2];
    if ((board[pos2_2] != 3) && eyedata[pos2_2].origin == eyedata[pos].origin) {
        eyedata[pos].neighbors++;
        if (eyedata[pos2_2].marginal)
            eyedata[pos].marginal_neighbors++;
    }

    int pos2_3 = pos + delta[3];
    if ((board[pos2_3] != 3) && eyedata[pos2_3].origin == eyedata[pos].origin) {
        eyedata[pos].neighbors++;
        if (eyedata[pos2_3].marginal)
            eyedata[pos].marginal_neighbors++;
    }
}
}
