#include <stdio.h>
#include <inttypes.h>

unsigned short line[16];
int x;
int i;
int maxx;
unsigned short *Picy;

void init_vars() {
    const int data_size = 16; 
    static unsigned short Picy_data[16];
    for (int idx = 0; idx < data_size; ++idx) {
        Picy_data[idx] = (unsigned short)(idx * 31);
    }
    Picy = Picy_data;
    x = 0;
    maxx = 16;
}