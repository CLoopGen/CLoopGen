#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern char active[400];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 21; k < 400; k += 2) {
        if (board[k] != 3)
            continue;
        if (active[k] != 0)
            continue;
        int up = k + 20;
        int down = k - 20;
        int left = k - 1;
        int right = k + 1;
        int cond = 0;
        if (up < 421 && board[up] != 3 && active[up] > 0 && active[up] < 4)
            cond = 1;
        else if (left > 0 && board[left] != 3 && active[left] > 0 && active[left] < 4)
            cond = 1;
        else if (down >= 0 && board[down] != 3 && active[down] > 0 && active[down] < 4)
            cond = 1;
        else if (right < 421 && board[right] != 3 && active[right] > 0 && active[right] < 4)
            cond = 1;
        if (cond)
            active[k] = 4;
    }
}
