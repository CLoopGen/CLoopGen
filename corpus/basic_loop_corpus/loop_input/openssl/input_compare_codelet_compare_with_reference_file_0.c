#include <inttypes.h>
#include <string.h>

char buf1[8192];
char buf2[8192];
size_t i;
size_t line_len;

void init_vars() {
    line_len = 8192;
    for (size_t idx = 0; idx < line_len; idx++) {
        buf1[idx] = (idx % 127 == 63) ? '?' : (char)(idx % 127);
        buf2[idx] = 0;
    }
}