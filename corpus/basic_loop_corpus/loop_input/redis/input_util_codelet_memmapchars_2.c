#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char *s;
size_t len;
char *from;
char *to;
size_t setlen;

void init_vars() {
    setlen = 256;
    from = malloc(setlen);
    to = malloc(setlen);
    
    for (size_t i = 0; i < setlen; i++) {
        from[i] = (char)i;
        to[i] = (char)((i + 1) % 256);
    }

    len = 64 * 1024 * 1024;
    s = malloc(len);
    if (!s) {
        exit(1);
    }

    srand((unsigned int)time(NULL));
    for (size_t j = 0; j < len; j++) {
        s[j] = (char)(rand() % 256);
    }
}