#include <stdio.h>
#include <inttypes.h>

typedef short word;
typedef long longword;

static word s_array[160];
word *s = s_array;
int k;

void init_vars() {
    for (int i = 0; i < 160; i++) {
        s[i] = (word)(i * 31);
    }
    k = 0;
}