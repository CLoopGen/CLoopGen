#include <inttypes.h>

int pieces[62];
int find_slot;

void init_vars() {
    for (int i = 0; i < 61; i++) {
        pieces[i] = 1;
    }
    pieces[61] = 0;
    find_slot = 0;
}