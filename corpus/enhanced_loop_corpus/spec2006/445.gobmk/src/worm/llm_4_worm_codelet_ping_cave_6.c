#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int mse[400];
extern int other;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if (board[pos] == 3 || !mse[pos]) continue;
    int cond1 = (!(board[((pos) + (19 + 1))] != 3) || board[((pos) + (19 + 1))] == other);
    int cond2 = (!(board[((pos) - (19 + 1))] != 3) || board[((pos) - (19 + 1))] == other);
    int cond3 = (!(board[((pos) - 1)] != 3) || board[((pos) - 1)] == other);
    int cond4 = (!(board[((pos) + 1)] != 3) || board[((pos) + 1)] == other);
    if ((cond1 && cond2) || (cond3 && cond4))
        mse[pos] = 0;
}
}
