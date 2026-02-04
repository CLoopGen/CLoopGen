#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;
typedef unsigned long ulongword;

word *LARp;
int i;
word temp;
longword ltmp;

static word LAR_buffer[256 * 1024]; // 512 KB of word data (256k elements)

void init_vars() {
    for (int j = 0; j < 256 * 1024; j++) {
        LAR_buffer[j] = (word)(j % 40000); // initialize with values up to ~40000 to cover condition ranges
    }
    LARp = LAR_buffer;
    i = 1;
    temp = 0;
    ltmp = 0;
}