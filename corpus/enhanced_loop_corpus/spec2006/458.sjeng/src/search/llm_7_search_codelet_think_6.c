#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int from;
    int target;
    int captured;
    int promoted;
    int castled;
    int ep;
} move_s;

extern move_s pv[300][300];
extern move_s dummy;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 300; i++)
    for (j = 0; j < 300; j++) {
        move_s temp = pv[(i + j) % 300][(299 - j) % 300];
        temp.from += dummy.from;
        pv[i][j] = temp;
    }
}
