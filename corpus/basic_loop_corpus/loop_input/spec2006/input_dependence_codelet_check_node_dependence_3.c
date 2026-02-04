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

int distance[13][13];
int j;
enum direction_type direction[13][13];

void init_vars() {
    for (int i = 0; i < 13; i++) {
        for (int k = 0; k < 13; k++) {
            distance[i][k] = 0;
            direction[i][k] = undef;
        }
    }
    j = 0;
}