#include <stdio.h>
#include <inttypes.h>

typedef long longword;

longword *L_ACF;
int k;

void init_vars() {
    const int data_size = 1 << 20; // 1 MB of data
    static longword acf_buffer[1 << 20]; // Sufficient size to cover index range up to k=9
    L_ACF = acf_buffer;
    k = 10; // Initialize k to 10 so that loop runs from 9 down to 0 inclusive
}