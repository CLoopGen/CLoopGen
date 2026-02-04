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



void loop() {
    int temp_dpos;
    for (dpos = (19 + 2); dpos < (19 + 1) * (19 + 1) && surrounded; dpos++) {
        temp_dpos = dpos; // Introduce temporary to create artificial WAW dependency
        if ((board[temp_dpos] != 3) && mf[temp_dpos]) {
            int up = temp_dpos - (19 + 1);
            int down = temp_dpos + (19 + 1);
            int right = temp_dpos + 1;
            int left = temp_dpos - 1;

            // Eliminate repeated calculations to change data flow (reduce RAW hazards)
            if (((board[up] != 3) && board[up] == 0 && 
                 (board[up - (19 + 1)] != 3) && board[up - (19 + 1)] == color && 
                 mn[up - (19 + 1)] != 1 &&
                 (board[up + 1] != 3) && board[up + 1] != other &&
                 (board[up - 1] != 3) && board[up - 1] != other) ||
                ((board[down] != 3) && board[down] == 0 && 
                 (board[down + (19 + 1)] != 3) && board[down + (19 + 1)] == color && 
                 mn[down + (19 + 1)] != 1 &&
                 (board[down + 1] != 3) && board[down + 1] != other &&
                 (board[down - 1] != 3) && board[down - 1] != other) ||
                ((board[right] != 3) && board[right] == 0 && 
                 (board[right + 1] != 3) && board[right + 1] == color && 
                 mn[right + 1] != 1 &&
                 (board[right - (19 + 1)] != 3) && board[right - (19 + 1)] != other &&
                 (board[right + (19 + 1)] != 3) && board[right + (19 + 1)] != other) ||
                ((board[left] != 3) && board[left] == 0 && 
                 (board[left - 1] != 3) && board[left - 1] == color && 
                 mn[left - 1] != 1 &&
                 (board[left - (19 + 1)] != 3) && board[left - (19 + 1)] != other &&
                 (board[left + (19 + 1)] != 3) && board[left + (19 + 1)] != other)) {
                surrounded = 0;
            }
        }
    }
}
