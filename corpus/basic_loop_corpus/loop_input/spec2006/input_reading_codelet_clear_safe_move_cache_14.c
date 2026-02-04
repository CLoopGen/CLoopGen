#include <inttypes.h>

int safe_move_cache_when[400][2];
int k;

void init_vars() {
    for (int i = 0; i < 400; i++) {
        safe_move_cache_when[i][0] = -1;
        safe_move_cache_when[i][1] = -1;
    }
}