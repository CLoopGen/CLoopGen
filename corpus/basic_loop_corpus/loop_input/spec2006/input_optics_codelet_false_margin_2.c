#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int pos;
int neighbors;
int k;
int delta[8];
Intersection board[421];

void init_vars() {
    pos = 200;
    neighbors = 0;
    for (int i = 0; i < 8; i++) {
        delta[i] = i * 37 - 150; 
    }
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 7) + 1;
    }
    board[pos] = 3;
    for (int i = 0; i < 8; i++) {
        int idx = pos + delta[i];
        if (idx >= 0 && idx < 421) {
            board[idx] = (i < 4) ? (i + 1) : 3;
        }
    }
}

void loop();