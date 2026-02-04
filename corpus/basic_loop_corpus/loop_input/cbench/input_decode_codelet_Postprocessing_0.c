#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;
typedef unsigned long ulongword;

word *s;
int k;
word msr;
longword ltmp;
word tmp;

#define DATA_SIZE (1 << 20) // 1MB of data: 524288 elements (each word is 2 bytes)
static word data[DATA_SIZE / sizeof(word)];

void init_vars() {
    s = data;
    k = 160;
    msr = 0;
    ltmp = 0;
    tmp = 0;

    for (int i = 0; i < DATA_SIZE / sizeof(word); i++) {
        data[i] = (word)(i & 32767);
    }
}