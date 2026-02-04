#include <stdio.h>
#include <inttypes.h>

unsigned short line[16];
int x;
int i;
int maxx;
unsigned short *Picy;

void init_vars() {
    maxx = 16;
    x = 0;
    Picy = (unsigned short*)__builtin_malloc(maxx * sizeof(unsigned short));
    for (i = 0; i < maxx; i++) {
        Picy[i] = (unsigned short)(i & 0xFFFF);
        line[i] = 0;
    }
}