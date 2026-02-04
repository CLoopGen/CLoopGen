#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int deltai[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int deltaj[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int delta[8];
Intersection board[421];
int permeability_array[400];
char safe[400];
int ii = 200;
int queue[400];
int d = 0;
int b = (int)(0.5 * (1 << 12));
int queue_start = 0;
int queue_end = 0;
int working[400];
int current_strength = (1 << 12);
int delta_i = 1;
int delta_j = 1;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        delta[i] = deltai[i] * (19 + 1) + deltaj[i];
    }

    for (int i = 0; i < 421; i++) {
        if (i < 400)
            board[i] = (i % 7 == 3) ? 3 : (i % 5 == 2 ? 1 : 0);
        else
            board[i] = 0;
    }

    for (int i = 0; i < 400; i++) {
        permeability_array[i] = (i % 97) * 100;
        safe[i] = (i % 13 == 0) ? 1 : 0;
        working[i] = 0;
    }

    for (int i = 0; i < 400; i++) {
        queue[i] = 0;
    }

    ii = 100;
    d = 0;
    queue_start = 0;
    queue_end = 0;
    current_strength = 4096;
    b = 2048;
    delta_i = 1;
    delta_j = 1;
}