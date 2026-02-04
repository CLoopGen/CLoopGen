#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

struct string_data {
    int color;
    int size;
    int origin;
    int liberties;
    int libs[20];
    int neighbors;
    int neighborlist[160];
    int mark;
};


extern Intersection board[421];
extern struct string_data string[240];
extern int ml[400];
extern int liberty_mark;
extern int s;
extern int k;
extern int s2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_liberties = string[s].liberties;
    int updated = 0;

    for (k = 0; k < string[s2].liberties; k++) {
        int pos2 = string[s2].libs[k];
        if ((board[pos2] == 0 && ml[pos2] != liberty_mark)) {
            if (local_liberties < 20) {
                string[s].libs[local_liberties] = pos2;
            }
            local_liberties++;
            ml[pos2] = liberty_mark;
            updated = 1;
        }
    }

    if (updated) {
        string[s].liberties = local_liberties;
    }
}
