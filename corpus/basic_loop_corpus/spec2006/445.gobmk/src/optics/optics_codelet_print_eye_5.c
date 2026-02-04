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


extern int board_size;
extern struct eye_data eye[400];
extern int m;
extern int n;
extern int mini;
extern int maxi;
extern int minj;
extern int maxj;
extern int origin;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (m = 0; m < board_size; m++)
    for (n = 0; n < board_size; n++) {
        if (eye[((19 + 2) + (m) * (19 + 1) + (n))].origin != origin)
            continue;
        if (m < mini)
            mini = m;
        if (m > maxi)
            maxi = m;
        if (n < minj)
            minj = n;
        if (n > maxj)
            maxj = n;
    }

}
