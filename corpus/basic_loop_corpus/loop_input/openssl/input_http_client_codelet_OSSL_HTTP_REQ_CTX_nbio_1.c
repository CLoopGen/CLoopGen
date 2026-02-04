#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int i;
long n = 131072; // 128KB of data
size_t resp_len = 0;
unsigned char *p;

void init_vars() {
    unsigned char *data = (unsigned char *)malloc(n);
    if (!data) {
        exit(1);
    }
    for (long idx = 0; idx < n; idx++) {
        data[idx] = (unsigned char)(idx & 0xFF);
    }
    p = data;
}