#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef const char *OPENSSL_CSTRING;

OPENSSL_CSTRING *b;
char *bb;

void init_vars() {
    size_t data_size = 512 * 1024;
    char *data = (char *)malloc(data_size);
    if (!data) return;

    memset(data, '0', data_size - 1);
    data[data_size - 1] = '1';

    b = (OPENSSL_CSTRING*)malloc(4 * sizeof(OPENSSL_CSTRING));
    if (!b) {
        free(data);
        return;
    }

    for (int i = 0; i < 4; i++) {
        b[i] = data;
    }
}