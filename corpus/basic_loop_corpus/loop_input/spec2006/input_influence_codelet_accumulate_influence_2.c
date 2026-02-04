#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int deltai[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int deltaj[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int delta[8];
Intersection board[421];
int permeability_array[400];
char safe[400];
int ii;
int queue[400];
int d;
int b = 4096;
int queue_start;
int queue_end;
int working[400];
int current_strength = 2048;
int delta_i = 1;
int delta_j = 1;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        delta[i] = deltai[i] * (19 + 1) + deltaj[i];
    }

    for (int i = 0; i < 421; i++) {
        if (i < 400)
            permeability_array[i] = 3000 + (i % 100);
        else
            permeability_array[i] = 0;

        safe[i] = (i % 7) == 0 ? 1 : 0;
        working[i] = 0;

        if (i < 400)
            queue[i] = 0;
    }

    for (int i = 0; i < 421; i++) {
        board[i] = (i % 13) == 0 ? 3 : 2;
    }

    ii = 200;
    queue_start = 0;
    queue_end = 0;
}