#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int v[262144];
int arbitrary_element;
int ph[51];
int bigm;
int r;
int kj;
int term;

void init_vars() {
    kj = 0;
    bigm = 262144;
    arbitrary_element = 42;
    term = 0;
    for (int i = 0; i < 51; i++) {
        ph[i] = rand() % 2;
    }
    for (int i = 0; i < 262144; i++) {
        v[i] = 0;
    }
}