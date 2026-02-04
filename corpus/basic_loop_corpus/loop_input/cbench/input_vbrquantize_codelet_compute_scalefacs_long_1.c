#include <stdio.h>
#include <inttypes.h>

typedef double FLOAT8;

int pretab[21];
int sfb;
FLOAT8 sf[21];
int ifqstep_inv;

void init_vars() {
    for (int i = 0; i < 21; i++) {
        pretab[i] = i * 1000000;
        sf[i] = 0.0;
    }
    ifqstep_inv = 1000000;
}

void loop();