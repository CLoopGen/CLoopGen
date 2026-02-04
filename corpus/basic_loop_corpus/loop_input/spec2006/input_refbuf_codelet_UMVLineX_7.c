#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned short line[16];
int x;
int width;
int i;
int maxx;
unsigned short *Picy;

void init_vars() {
    const size_t picy_size = 1024 * 1024 / sizeof(unsigned short);
    unsigned short *picy_data = (unsigned short *)calloc(picy_size, sizeof(unsigned short));
    Picy = picy_data;

    x = 8;
    width = 10;
    maxx = 16;
}