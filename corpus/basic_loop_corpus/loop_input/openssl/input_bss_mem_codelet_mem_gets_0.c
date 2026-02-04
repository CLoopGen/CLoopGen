#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int i;
int j;
char *p;

void init_vars() {
    j = 131072;  // 128 KB of data
    p = (char *)malloc(j);
    if (!p) {
        exit(1);
    }
    memset(p, 'a', j);
    p[j - 1] = '\n';  // Ensure newline near the end so loop breaks after many iterations
}

__attribute__((constructor))
static void constructor() {
    init_vars();
}