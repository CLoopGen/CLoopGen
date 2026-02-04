#include <inttypes.h>

int m = 10;
unsigned int a = 0xdeadbeef;
unsigned int x[25];
int i;

void init_vars() {
    m = 10;
    a = 0xdeadbeef;
    i = 0;

    for (int idx = 0; idx < 25; idx++) {
        x[idx] = idx * 17 + 1;
    }
}