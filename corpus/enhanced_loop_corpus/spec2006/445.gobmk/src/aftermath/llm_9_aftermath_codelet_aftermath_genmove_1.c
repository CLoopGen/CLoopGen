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
        int updates = 0;
        for (k = 0; k < 8; k++) {
            int pos2 = pos + delta[k];
            if (pos2 < 0 || pos2 >= 421) continue;
            if (board[pos2] == 3) continue;
            if ((d == 0 || board[pos2] == 0) && (distance[pos2] == d || distance[pos2] == d - 1)) {
                distance[pos] = d + 1;
                something_found = 1;
                updates++;
                if (d > 0) {
                    if (board[pos] == other && closest_opponent == 0) {
                        closest_opponent = pos;
                    } else if (board[pos] == color && closest_own == 0) {
                        closest_own = pos;
                    }
                }
            }
        }
        if (updates > 1) {
            distance[pos] += 1;
        }
    }
}
}
