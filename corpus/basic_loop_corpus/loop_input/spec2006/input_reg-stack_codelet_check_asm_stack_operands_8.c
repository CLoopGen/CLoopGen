#include <inttypes.h>

int i;
char implicitly_dies[53] = {0};

void init_vars() {
    for (int idx = 0; idx < 53; idx++) {
        implicitly_dies[idx] = 0;
    }
    implicitly_dies[8 + 7] = 1;
}