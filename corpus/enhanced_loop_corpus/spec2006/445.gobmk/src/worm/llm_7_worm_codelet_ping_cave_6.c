#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int mse[400];
extern int other;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 19 + 1;
    int N = stride * stride;
    // Introduce loop-carried dependence via temporary accumulation
    int prev_pos = 0;
    for (pos = (19 + 2); pos < N; pos++) {
        if (pos > (19 + 2)) {
            // Create WAW and RAW dependency: current iteration depends on previous write to mse
            mse[pos] = mse[prev_pos] ? mse[pos] : 0;
        }
        prev_pos = pos;
        if ((board[pos] != 3) && mse[pos]) {
            char cond_vertical = 1;
            char cond_horizontal = 1;

            if (board[pos + stride] != 3)
                cond_vertical &= (board[pos + stride] == other);
            if (board[pos - stride] != 3)
                cond_vertical &= (board[pos - stride] == other);

            if (board[pos - 1] != 3)
                cond_horizontal &= (board[pos - 1] == other);
            if (board[pos + 1] != 3)
                cond_horizontal &= (board[pos + 1] == other);

            if (cond_vertical || cond_horizontal)
                mse[pos] = 0;
        }
    }
}
