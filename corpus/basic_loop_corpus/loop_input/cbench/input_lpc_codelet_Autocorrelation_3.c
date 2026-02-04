#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;

word *s;
int k;

static word s_data[131072]; // 131072 * sizeof(short) = 256 KB of data

void init_vars() {
    s = s_data;
    for (int i = 0; i < 131072; i++) {
        s[i] = (word)(i & 0xFFFF);
    }
    k = 0;
}