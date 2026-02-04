#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int delta[8] = {1, -1, 19, -19, 2, -2, 3, -3};

Intersection board[421];

int color = 1;
int k;
int other = 2;
int distance[400];
int something_found;
int closest_opponent;
int closest_own;
int d = 5;

int pos;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 7 == 0) ? 3 : (i % 3 + 1);
    }
    
    for (int i = 0; i < 400; i++) {
        distance[i] = (i % 10 == 0) ? 5 : -1;
    }
    
    something_found = 0;
    closest_opponent = 0;
    closest_own = 0;
    d = 5;
}