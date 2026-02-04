#include <inttypes.h>

int i;
int top;
unsigned long *bdp;

static unsigned long bdp_storage[16384];

void init_vars() {
    top = 16384;
    bdp = bdp_storage;
}