#include <stdio.h>
#include <inttypes.h>

enum direction_type {
    lt,
    le,
    eq,
    gt,
    ge,
    star,
    independent,
    undef
};

enum direction_type direction[13][13];
int distance[13][13];
int loop_count;
int subscript_count;
int i;
int j;
int sign;
enum direction_type direction_merge[8][8];

void init_vars() {
    loop_count = 12;
    subscript_count = 12;

    for (int i = 0; i <= loop_count; i++) {
        for (int j = 0; j <= subscript_count; j++) {
            distance[i][j] = (i + j) % 7 - 3; 
            direction[i][j] = (enum direction_type)((i * j + 1) % 8);
        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            direction_merge[i][j] = (enum direction_type)((i + j) % 8);
        }
    }

    i = 0;
    j = 0;
    sign = 1;
}