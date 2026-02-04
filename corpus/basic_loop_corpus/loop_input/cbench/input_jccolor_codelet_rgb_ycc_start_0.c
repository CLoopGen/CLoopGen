#include <inttypes.h>

typedef long INT32;

INT32 *rgb_ycc_tab;
INT32 i;

static INT32 rgb_ycc_data[8 * (255 + 1)];

void init_vars() {
    rgb_ycc_tab = rgb_ycc_data;
    i = 0;
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}