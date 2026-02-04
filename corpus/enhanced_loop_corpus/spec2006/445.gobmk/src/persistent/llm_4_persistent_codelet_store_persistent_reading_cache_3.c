#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = (19 + 2); k < (19 + 1) * (19 + 1); k++) {
    if (board[k] == 3) continue;
    if (active[k] != 0) continue;

    int up = (k) + (19 + 1);
    int left = (k) - 1;
    int down = (k) - (19 + 1);
    int right = (k) + 1;

    int cond = 0;
    if (board[up] != 3 && active[up] > 0 && active[up] < 4) cond = 1;
    else if (board[left] != 3 && active[left] > 0 && active[left] < 4) cond = 1;
    else if (board[down] != 3 && active[down] > 0 && active[down] < 4) cond = 1;
    else if (board[right] != 3 && active[right] > 0 && active[right] < 4) cond = 1;

    if (cond)
        active[k] = 4;
}
}
