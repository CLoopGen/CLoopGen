#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

char **fontlist;
char **listhead;
int fonts;
int i;

#define DATA_SIZE (128 << 20) // 128 MB of data

static char *data_pool;
static char **temp_listhead;
static char **temp_fontlist;

void init_vars() {
    fonts = DATA_SIZE / sizeof(char*);

    data_pool = (char*)calloc(fonts * 2, sizeof(char*));
    if (!data_pool) {
        fonts = 0;
        return;
    }

    temp_listhead = (char**)data_pool;
    temp_fontlist = temp_listhead + fonts;

    for (int idx = 0; idx < fonts; idx++) {
        temp_listhead[idx] = (char*)(temp_listhead + fonts + idx);
        sprintf(temp_listhead[idx], "font_%d", idx);
    }

    fontlist = temp_fontlist;
    listhead = temp_listhead;
}