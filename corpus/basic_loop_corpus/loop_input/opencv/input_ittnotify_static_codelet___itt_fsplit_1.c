#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char *s;
char *sep;
int *len;
int i;
int j;

static char s_buffer[131072];
static char sep_buffer[5] = " \t\n\r";
static int len_storage;

void init_vars() {
    size_t data_size = 131072;
    size_t sep_size = 4;

    for (size_t idx = 0; idx < data_size - 1; idx++) {
        s_buffer[idx] = 'a' + (idx % 26);
    }
    s_buffer[data_size - 1] = '\0';

    s = s_buffer;
    sep = sep_buffer;
    len = &len_storage;
    i = 0;
    j = 0;
    len_storage = 0;
}