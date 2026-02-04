#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int y;
int s[10];

void init_vars() {
    y = 0;
    for (int i = 0; i < 10; i++) {
        s[i] = rand() | (rand() << 16);
    }
}