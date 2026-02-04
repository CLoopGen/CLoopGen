#include <stdlib.h>
#include <stddef.h>

typedef long JLONG;

JLONG *rgb_ycc_tab;
JLONG i;

void init_vars() {
    size_t total_size = 8 * (255 + 1);
    rgb_ycc_tab = (JLONG*)calloc(total_size, sizeof(JLONG));
}

void loop();