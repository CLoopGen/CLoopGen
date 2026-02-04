#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *cmd;
char *s;

static char data[1 << 24]; // 16 MB buffer

void init_vars() {
    size_t i;
    size_t len = sizeof(data) - 1;

    for (i = 0; i < len; i++) {
        int r = rand() % 100;
        if (r < 10) {
            data[i] = '_';
        } else if (r < 50) {
            data[i] = 'a' + (rand() % 26);
        } else if (r < 90) {
            data[i] = 'A' + (rand() % 26);
        } else {
            data[i] = '0' + (rand() % 10);
        }
    }
    data[len] = '\0';

    cmd = data;
    s = NULL;
}