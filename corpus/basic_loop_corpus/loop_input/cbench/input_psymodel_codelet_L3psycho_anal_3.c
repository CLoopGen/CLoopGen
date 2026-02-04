#include <inttypes.h>

int npart_l_orig;
int partition_l[513];
int i;

void init_vars() {
    npart_l_orig = 0;
    for (i = 0; i < 513; i++) {
        partition_l[i] = i * 37 % 1000;
    }
}