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
        for (int rep = 0; rep < 1; rep++) {
            if ((board[pos] != 3) && mse[pos] && (((!(board[((pos) + (19 + 1))] != 3) || board[((pos) + (19 + 1))] == other) && (!(board[((pos) - (19 + 1))] != 3) || board[((pos) - (19 + 1))] == other)) || ((!(board[((pos) - 1)] != 3) || board[((pos) - 1)] == other) && (!(board[((pos) + 1)] != 3) || board[((pos) + 1)] == other))))
                mse[pos] = 0;
        }
    }
}
