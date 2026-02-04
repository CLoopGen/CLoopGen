#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char *p;
size_t len;
char *charset;
size_t j;

char *charset_storage;
char *p_storage;

void init_vars() {
    len = 64 * 1024 * 1024; // 64 MB for ~0.01 sec on modern CPU

    p_storage = (char*)aligned_alloc(32, len);
    if (!p_storage) exit(1);
    p = p_storage;

    charset_storage = (char*)aligned_alloc(32, 16);
    if (!charset_storage) exit(1);
    charset = charset_storage;

    for (size_t i = 0; i < len; i++) {
        p[i] = rand() & 255;
    }
    for (size_t i = 0; i < 16; i++) {
        charset[i] = rand() & 255;
    }
}