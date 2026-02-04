#include <stdio.h>
#include <inttypes.h>

typedef short word;

word *drp;
int k;

static word data[128000]; // 128000 elements to ensure safe indexing

void init_vars() {
    drp = &data[120]; // Base pointer offset to allow -120+k access
}

// The loop function is declared in another file, so we don't redefine it here.