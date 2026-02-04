#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char **fontlist;
char **listhead;
int fonts;
int i;

#define DATA_SIZE_MB 64
#define NUM_STRINGS (DATA_SIZE_MB * (1 << 20) / sizeof(char*))

static char* dummy_strings[NUM_STRINGS];

void init_vars() {
    fonts = NUM_STRINGS;

    for (int idx = 0; idx < NUM_STRINGS; idx++) {
        dummy_strings[idx] = malloc(16);
        if (dummy_strings[idx]) {
            sprintf(dummy_strings[idx], "str%d", idx);
        }
    }

    listhead = dummy_strings;

    fontlist = malloc(fonts * sizeof(char*));
    if (!fontlist) {
        fonts = 0;
        return;
    }

    for (int idx = 0; idx < fonts; idx++) {
        fontlist[idx] = NULL;
    }
}