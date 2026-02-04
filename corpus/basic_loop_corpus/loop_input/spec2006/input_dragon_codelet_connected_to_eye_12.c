#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

int delta[8] = { -42, -41, -1, 1, 41, 42, 100, -100 };
Intersection board[421];
int pos = 210;
char mx[400];
int k;

void init_vars() {
    for (int i = 0; i < 8; i++) {
        delta[i] = (i % 2 == 0) ? -delta[i] : delta[i];
    }
    
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 7 == 0) ? 3 : (i % 5);
    }
    
    for (int i = 0; i < 400; i++) {
        mx[i] = 0;
    }
    
    pos = 200;
}