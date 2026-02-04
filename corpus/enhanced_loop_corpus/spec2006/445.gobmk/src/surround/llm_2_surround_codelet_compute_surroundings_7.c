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
    int directions[4] = { -(19+1), (19+1), 1, -1 };
    for (dpos = (19 + 2); dpos < (19 + 1) * (19 + 1) && surrounded; dpos++) {
        if ((board[dpos] != 3) && mf[dpos]) {
            int dir;
            for (dir = 0; dir < 4 && surrounded; dir++) {
                int neighbor = dpos + directions[dir];
                int far = neighbor + directions[dir];
                int perp1 = neighbor + 1;
                int perp2 = neighbor - 1;
                if (directions[dir] == 1 || directions[dir] == -1) {
                    perp1 = neighbor - (19+1);
                    perp2 = neighbor + (19+1);
                }
                if ((board[neighbor] != 3) && board[neighbor] == 0 &&
                    (board[far] != 3) && board[far] == color &&
                    mn[far] != 1 &&
                    (board[perp1] != 3) && board[perp1] != other &&
                    (board[perp2] != 3) && board[perp2] != other) {
                    surrounded = 0;
                }
            }
        }
    }
}
