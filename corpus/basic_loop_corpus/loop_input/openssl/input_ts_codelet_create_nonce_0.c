#include <inttypes.h>

unsigned char buf[1024 * 128];
int len = 1024 * 128;
int i;

void init_vars() {
    for (int j = 0; j < len; ++j) {
        buf[j] = 0;
    }
    buf[len - 1] = 1;
    i = 0;
    len = 1024 * 128;
}