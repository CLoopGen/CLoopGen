#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

long freq[257];
int codesize[257];
int others[257];
int c1;
int c2;
int i;
int num_nz_symbols;
long v;
long v2;

void init_vars() {
    num_nz_symbols = 256;
    
    for (int j = 0; j < 256; j++) {
        freq[j] = rand() % 100000 + 1;
        codesize[j] = 0;
        others[j] = -1;
    }
    
    freq[256] = 0;
    codesize[256] = 0;
    others[256] = -1;
    
    c1 = -1;
    c2 = -1;
    v = 1000000000L;
    v2 = 1000000000L;
}