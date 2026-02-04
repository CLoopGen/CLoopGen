#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

long long padlen = 67108864; // 64MB size for ~0.01 sec on modern CPU
char *ch;
char *buf;

void init_vars() {
    buf = aligned_alloc(64, padlen);
    ch = aligned_alloc(64, sizeof(char));
    *ch = 'A';
    if (!buf || !ch) {
        exit(1);
    }
}