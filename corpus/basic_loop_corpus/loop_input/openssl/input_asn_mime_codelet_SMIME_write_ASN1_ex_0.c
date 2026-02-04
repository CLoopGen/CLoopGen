#include <inttypes.h>

char bound[33] = {0};
char c;
int i;

void init_vars() {
    for (i = 0; i < 32; i++) {
        bound[i] = (char)(i * 7 + 13);
    }
    bound[32] = 0;
    c = 0;
    i = 0;
}