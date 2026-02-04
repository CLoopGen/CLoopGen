#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int mse[400];
extern int other;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride for cache behavior alteration
    // We traverse the array in reverse order with a stride of 2 to modify access pattern
    int size = (19 + 1) * (19 + 1);
    int start = size - 1;
    for (pos = start; pos >= (19 + 2); pos -= 2) {
        if ((board[pos] != 3) && mse[pos]) {
            int cond1 = (!(board[pos + (19 + 1)] != 3) || board[pos + (19 + 1)] == other);
            int cond2 = (!(board[pos - (19 + 1)] != 3) || board[pos - (19 + 1)] == other);
            int cond3 = (!(board[pos - 1] != 3) || board[pos - 1] == other);
            int cond4 = (!(board[pos + 1] != 3) || board[pos + 1] == other);
            if ((cond1 && cond2) || (cond3 && cond4))
                mse[pos] = 0;
        }
    }
    // Handle remaining index if needed (pos == 19+2 was skipped due to stride)
    pos = (19 + 2);
    if (pos % 2 == 1) { // if starting point was odd and we missed it
        if ((board[pos] != 3) && mse[pos]) {
            int cond1 = (!(board[pos + (19 + 1)] != 3) || board[pos + (19 + 1)] == other);
            int cond2 = (!(board[pos - (19 + 1)] != 3) || board[pos - (19 + 1)] == other);
            int cond3 = (!(board[pos - 1] != 3) || board[pos - 1] == other);
            int cond4 = (!(board[pos + 1] != 3) || board[pos + 1] == other);
            if ((cond1 && cond2) || (cond3 && cond4))
                mse[pos] = 0;
        }
    }
}
