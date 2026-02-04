#include <inttypes.h>

unsigned short data[128 * 1024 * 1024 / sizeof(unsigned short)]; // 128MB buffer
unsigned short *x = data;
int i;

void init_vars() {
    x = data;
    i = 0;
}