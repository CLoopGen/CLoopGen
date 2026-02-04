#include <stdlib.h>
#include <stddef.h>

int others[257];
int i;

void init_vars() {
    for (int j = 0; j < 257; j++) {
        others[j] = 0;
    }
    i = 0;
}