#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *tgt;
char *src;
int len;
int i;
long case_adjust;

void init_vars() {
    len = 512 * 1024; // 512 KB data size for ~0.01 sec runtime estimate

    src = (char*)malloc(len + 1);
    tgt = (char*)malloc(len + 1);

    if (!src || !tgt) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < len; j++) {
        src[j] = (char)(33 + (j % 94)); // printable ASCII range ('!' to '~')
    }
    src[len] = '\x00'; // null terminate

    case_adjust = 0xDF; // typical value to force uppercase in ASCII when ANDed
}

__attribute__((constructor))
static void constructor_init() {
    init_vars();
}