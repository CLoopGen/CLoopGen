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
int temp_esize[400] = {0};
int temp_msize[400] = {0};
char temp_neighbors[400] = {0};
char temp_marginal_neighbors[400] = {0};

for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if (!(board[pos] != 3) || eyedata[pos].origin == 0)
        continue;
    int origin_idx = eyedata[pos].origin;
    temp_esize[pos] = eyedata[origin_idx].esize;
    temp_msize[pos] = eyedata[origin_idx].msize;
    temp_neighbors[pos] = 0;
    temp_marginal_neighbors[pos] = 0;
    for (k = 0; k < 4; k++) {
        int pos2 = pos + delta[k];
        if ((board[pos2] != 3) && eyedata[pos2].origin == origin_idx) {
            temp_neighbors[pos]++;
            if (eyedata[pos2].marginal)
                temp_marginal_neighbors[pos]++;
        }
    }
}

for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if (!(board[pos] != 3) || eyedata[pos].origin == 0)
        continue;
    eyedata[pos].esize = temp_esize[pos];
    eyedata[pos].msize = temp_msize[pos];
    eyedata[pos].neighbors = temp_neighbors[pos];
    eyedata[pos].marginal_neighbors = temp_marginal_neighbors[pos];
}
}
