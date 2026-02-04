#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef char *sds;

char *from;
char *to;
size_t setlen;
size_t j;
size_t i;
size_t l;
sds s;

void init_vars() {
    setlen = 256;
    l = (1 << 20); // 1MB of data

    from = malloc(setlen);
    to = malloc(setlen);
    s = malloc(l);

    if (!from || !to || !s) {
        exit(1);
    }

    for (size_t idx = 0; idx < setlen; idx++) {
        from[idx] = (char)(idx);
        to[idx] = (char)(idx + 1);
    }

    for (size_t idx = 0; idx < l; idx++) {
        s[idx] = (char)(rand() % 256);
    }
}