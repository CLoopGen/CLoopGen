#include <inttypes.h>

unsigned char *md;
unsigned int len;
unsigned int i;

void init_vars() {
    len = 512 * 1024; // 512 KB data size for ~0.01 sec runtime
    md = (unsigned char*)__builtin_malloc(len);
}