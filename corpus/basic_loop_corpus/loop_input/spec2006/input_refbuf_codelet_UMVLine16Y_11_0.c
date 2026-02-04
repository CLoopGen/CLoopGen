#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned short line[16];
int x;
int i;
int maxx;
unsigned short *Picy;

void init_vars() {
    x = 0;
    maxx = 16;
    Picy = (unsigned short*)calloc(1, sizeof(unsigned short));
    if (!Picy) {
        exit(1);
    }
    Picy[0] = 42;
}