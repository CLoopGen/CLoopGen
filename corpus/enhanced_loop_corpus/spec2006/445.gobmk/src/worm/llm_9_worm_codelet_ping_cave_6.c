#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int pos;
extern int mse[400];
extern int other;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    const int START_POS = 21;
    const int STEP = 3;
    int local_mse;
    int idx, neighbor;

    for (pos = START_POS; pos < 400; pos += STEP) {
        if (board[pos] == 3) continue;
        local_mse = mse[pos];
        if (!local_mse) continue;

        // Check vertical neighbors: down then up
        neighbor = pos - 20;
        int vert_ok = (board[neighbor] == 3 || board[neighbor] == other);
        neighbor = pos + 20;
        vert_ok &= (board[neighbor] == 3 || board[neighbor] == other);

        // Check horizontal neighbors: left then right
        neighbor = pos - 1;
        int horiz_ok = (board[neighbor] == 3 || board[neighbor] == other);
        neighbor = pos + 1;
        horiz_ok &= (board[neighbor] == 3 || board[neighbor] == other);

        if (vert_ok || horiz_ok)
            mse[pos] = 0;
    }
}
