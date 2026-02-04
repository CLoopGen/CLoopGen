#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
char goal[400];
int ii;
int mx[400];
int queue[361];
int queue_end;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i < 400) ? (i % 7) : 0;
    }
    for (int i = 0; i < 400; i++) {
        goal[i] = (i % 5) ? 1 : 0;
        mx[i] = 0;
    }
    for (int i = 0; i < 361; i++) {
        queue[i] = 0;
    }
    queue_end = 0;
}