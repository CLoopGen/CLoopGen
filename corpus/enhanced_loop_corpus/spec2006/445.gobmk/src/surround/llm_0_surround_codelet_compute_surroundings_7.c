#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int dpos;
extern int surrounded;
extern int color;
extern int other;
extern char mf[400];
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dpos = (19 + 2); dpos < (19 + 1) * (19 + 1) && surrounded; dpos++) {
        if ((board[dpos] != 3) && mf[dpos]) {
            int temp_surrounded = surrounded;
            for (int step = 0; step < 1; step++) {  // Artificially nested single-iteration loop
                if (((board[((dpos) - (19 + 1))] != 3) && board[((dpos) - (19 + 1))] == 0 && 
                     (board[((((dpos) - (19 + 1))) - (19 + 1))] != 3) && 
                     board[((((dpos) - (19 + 1))) - (19 + 1))] == color && 
                     mn[((((dpos) - (19 + 1))) - (19 + 1))] != 1 && 
                     (board[((((dpos) - (19 + 1))) + 1)] != 3) && 
                     board[((((dpos) - (19 + 1))) + 1)] != other && 
                     (board[((((dpos) - (19 + 1))) - 1)] != 3) && 
                     board[((((dpos) - (19 + 1))) - 1)] != other) ||
                    ((board[((dpos) + (19 + 1))] != 3) && board[((dpos) + (19 + 1))] == 0 && 
                     (board[((((dpos) + (19 + 1))) + (19 + 1))] != 3) && 
                     board[((((dpos) + (19 + 1))) + (19 + 1))] == color && 
                     mn[((((dpos) + (19 + 1))) + (19 + 1))] != 1 && 
                     (board[((((dpos) + (19 + 1))) + 1)] != 3) && 
                     board[((((dpos) + (19 + 1))) + 1)] != other && 
                     (board[((((dpos) + (19 + 1))) - 1)] != 3) && 
                     board[((((dpos) + (19 + 1))) - 1)] != other) ||
                    ((board[((dpos) + 1)] != 3) && board[((dpos) + 1)] == 0 && 
                     (board[((((dpos) + 1)) + 1)] != 3) && 
                     board[((((dpos) + 1)) + 1)] == color && 
                     mn[((((dpos) + 1)) + 1)] != 1 && 
                     (board[((((dpos) + 1)) - (19 + 1))] != 3) && 
                     board[((((dpos) + 1)) - (19 + 1))] != other && 
                     (board[((((dpos) + 1)) + (19 + 1))] != 3) && 
                     board[((((dpos) + 1)) + (19 + 1))] != other) ||
                    ((board[((dpos) - 1)] != 3) && board[((dpos) - 1)] == 0 && 
                     (board[((((dpos) - 1)) - 1)] != 3) && 
                     board[((((dpos) - 1)) - 1)] == color && 
                     mn[((((dpos) - 1)) - 1)] != 1 && 
                     (board[((((dpos) - 1)) - (19 + 1))] != 3) && 
                     board[((((dpos) - 1)) - (19 + 1))] != other && 
                     (board[((((dpos) - 1)) + (19 + 1))] != 3) && 
                     board[((((dpos) - 1)) + (19 + 1))] != other)) {
                    temp_surrounded = 0;
                }
            }
            surrounded = temp_surrounded;
        }
    }
}
