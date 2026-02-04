#include <stdint.h>
#include <stdlib.h>

int *tab;
int i;
int xr;
int *xp;

static int tab_data[32];
static int xp_data[8];

void init_vars() {
    tab = tab_data;
    xp = xp_data;
    for (int idx = 0; idx < 32; ++idx) {
        tab_data[idx] = rand() % 1000;
    }
    for (int idx = 0; idx < 8; ++idx) {
        xp_data[idx] = (rand() % 1000) + 1;
    }
    i = 0;
    xr = 0;
}