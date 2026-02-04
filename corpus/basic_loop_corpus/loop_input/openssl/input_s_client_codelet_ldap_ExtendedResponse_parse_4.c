#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

unsigned char *cur;
long len;
int inf;
int ret;

static unsigned char *cur_storage;

void init_vars() {
    len = 512 * 1024; // 512 KB data size for ~0.01 sec runtime estimate

    cur_storage = (unsigned char *)malloc(len);
    if (!cur_storage) {
        ret = -1;
        return;
    }

    memset(cur_storage, 0xFF, len); // Initialize with non-zero pattern

    cur = cur_storage;
    inf = 0;
    ret = 0;
}