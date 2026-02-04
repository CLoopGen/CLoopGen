#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
int replacement_map[400];
int from;
int pos;

void init_vars() {
    from = 100;
    
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 4 == 0) ? 3 : (i % 5);
    }
    
    for (int i = 0; i < 400; i++) {
        replacement_map[i] = i;
    }
}

void loop();