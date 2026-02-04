#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <math.h>

typedef struct {
    double xdbl[12];
    double ydbl[12];
    double carry;
    float xflt[24];
    unsigned int ir;
    unsigned int jr;
    unsigned int is;
    unsigned int is_old;
    unsigned int pr;
} ranlxs_state_t;

double one_bit = 1.0 / 281474976710656.0; // 2^-48
ranlxs_state_t *state;
int ibit = 0;
int jbit = 16;
int k;
int m;
int xbit[31];
double x;
double y;

void init_vars() {
    state = (ranlxs_state_t*)aligned_alloc(64, sizeof(ranlxs_state_t));
    if (!state) exit(1);

    memset(state, 0, sizeof(ranlxs_state_t));

    for (int i = 0; i < 31; ++i) {
        xbit[i] = i & 1;
    }

    ibit = 0;
    jbit = 16;
    x = 0.0;
    y = 0.0;
}