#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int color;
extern int k;
extern int other;
extern int distance[400];
extern int something_found;
extern int closest_opponent;
extern int closest_own;
extern int d;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (pos = (19 + 2); pos < (19 + 1) * (19 + 1); pos++) {
    if ((board[pos] != 3) && distance[pos] == -1) {
        for (k = 0; k < 4; k++) {
            int pos2 = pos + delta[k];
            if (!(board[pos2] != 3))
                continue;
            if ((d == 0 || board[pos2] == 0) && distance[pos2] == d) {
                for (int shadow_d = 0; shadow_d <= d; shadow_d++) {
                    if (shadow_d == d) {
                        if (d > 0 && board[pos] == other) {
                            distance[pos] = d + 1;
                            if (closest_opponent == 0)
                                closest_opponent = pos;
                        } else if (d > 0 && board[pos] == color) {
                            distance[pos] = d + 1;
                            if (closest_own == 0)
                                closest_own = pos;
                        } else if (board[pos] == 0) {
                            distance[pos] = d + 1;
                            something_found = 1;
                        }
                    }
                }
                break;
            }
        }
    }
}
}
