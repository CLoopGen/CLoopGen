#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

unsigned short line[16];
int x;
int i;
int maxx;
unsigned short *Picy;

void init_vars() {
    const int num_elements = 128 * 1024 * 1024 / sizeof(unsigned short);
    unsigned short *dynamic_array = (unsigned short *)calloc(num_elements, sizeof(unsigned short));
    Picy = dynamic_array;

    x = 0;
    maxx = 16;
}