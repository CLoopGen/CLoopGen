#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *PL_bufend;
char *s;
char *t;

static char *buffer;
static char *s_content;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime on modern CPU

    buffer = (char *)malloc(data_size);
    s_content = (char *)malloc(2);

    if (!buffer || !s_content) {
        exit(1);
    }

    memset(buffer, 'a', data_size);
    buffer[data_size - 1] = '\0';
    buffer[data_size - 2] = 'b';

    buffer[0] = '\\';
    buffer[1] = '\\';
    buffer[2] = 'c';

    s_content[0] = 'b';
    s_content[1] = '\0';

    PL_bufend = buffer + data_size - 1;
    s = s_content;
    t = buffer;
}