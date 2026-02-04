#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef unsigned char Intersection;

Intersection board[421];
int gb[400];
int bubbles[400];
int ii;
int found_one;

void init_vars() {
    const int N = 19;
    const int SIZE = (N + 2) * (N + 2);
    
    for (int i = 0; i < 421; i++) {
        board[i] = (i < SIZE) ? ((i % 7) < 3 ? 1 : ((i % 7) < 5 ? 2 : 3)) : 3;
    }
    
    for (int i = 0; i < 400; i++) {
        gb[i] = (i % 17 == 0) ? 0 : ((i % 13 == 0) ? 1 : ((i % 11 == 0) ? -1 : ((i % 2) ? 2 : -2)));
        bubbles[i] = (i % 19 == 0) ? 3 : ((i % 13 == 0) ? 1 : ((i % 11 == 0) ? 2 : 0));
    }
    
    ii = 0;
    found_one = 0;
}