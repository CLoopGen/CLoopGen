#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
int string_number[400];
int pos;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i % 4 == 0) ? 3 : (i % 3); 
    }
    for (int i = 0; i < 400; i++) {
        string_number[i] = i;
    }
    pos = 0;
}