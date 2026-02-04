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
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if (!(board[pos] != 3) || eyedata[pos].origin == 0)
        continue;
    eyedata[pos].esize = eyedata[eyedata[pos].origin].esize;
    eyedata[pos].msize = eyedata[eyedata[pos].origin].msize;
    eyedata[pos].neighbors = 0;
    eyedata[pos].marginal_neighbors = 0;
    for (k = 0; k < 2; k++) {
        int pos2 = pos + delta[k];
        if ((board[pos2] != 3) && eyedata[pos2].origin == eyedata[pos].origin) {
            eyedata[pos].neighbors++;
            if (eyedata[pos2].marginal)
                eyedata[pos].marginal_neighbors++;
        }
    }
    for (k = 2; k < 4; k++) {
        int pos2 = pos + delta[k];
        if ((board[pos2] != 3) && eyedata[pos2].origin == eyedata[pos].origin) {
            eyedata[pos].neighbors++;
            if (eyedata[pos2].marginal)
                eyedata[pos].marginal_neighbors++;
        }
    }
}
}
