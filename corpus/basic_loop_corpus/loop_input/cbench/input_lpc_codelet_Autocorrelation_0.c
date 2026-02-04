#include <inttypes.h>

typedef short word;

word s_array[160] __attribute__((aligned(32)));
const int array_size = 160;

word *s = s_array;
int k;
word temp;
word smax;

void init_vars() {
    smax = -32768;
    for (int i = 0; i < array_size; i++) {
        s[i] = (word)(i * 179 % 40000 - 20000);
    }
}