#include <stdint.h>

typedef short word;

word scalauto = 1;
int k;
word *s;

word s_array[65536];

void init_vars() {
    for (int i = 0; i < 65536; ++i) {
        s_array[i] = (word)(i & 0xFFFF);
    }
    s = s_array;
    k = 160;
}