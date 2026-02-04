#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;

word *s;
int k;

static word s_data[131072]; // 131072 words = 262144 bytes (~256KB), allows k up to at least 159

void init_vars() {
    s = s_data;
    for (int i = 0; i < 131072; i++) {
        s[i] = (word)(i & 0x7FFF); // Initialize with non-zero pattern within short range
    }
    k = 0;
}