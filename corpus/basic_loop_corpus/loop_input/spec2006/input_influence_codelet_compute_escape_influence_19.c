#include <stdio.h>
#include <inttypes.h>

typedef unsigned char Intersection;

Intersection board[421];
char escape_value[400];
int ii;
char escape_values[400][2];
int cache_number;

void init_vars() {
    for (int i = 0; i < 421; i++) {
        board[i] = (i < 400) ? (i % 3) : 0;
    }
    for (int i = 0; i < 400; i++) {
        escape_value[i] = (char)(i % 256);
        escape_values[i][0] = 0;
        escape_values[i][1] = 0;
    }
    cache_number = 0;
    ii = 0;
}