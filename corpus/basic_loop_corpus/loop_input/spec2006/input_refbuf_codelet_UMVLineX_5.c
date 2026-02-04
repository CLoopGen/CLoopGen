#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned short line[16];
int x;
int i;
int maxx;
unsigned short *Picy;

void init_vars() {
    maxx = 16;
    x = 0;
    Picy = (unsigned short *)calloc(maxx, sizeof(unsigned short));
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}