#include <inttypes.h>

int k;
int active_caches[2];

void init_vars() {
    k = 0;
    for (int i = 0; i < 2; i++) {
        active_caches[i] = 0;
    }
}