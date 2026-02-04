#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

char start_color[268435456]; // 256 MB
char *p;

static void init_array() {
    size_t len = sizeof(start_color) - 1;
    size_t i = 0;
    while (i < len - 10) {
        int r = rand() % 100;
        if (r < 70) {
            start_color[i++] = 'a' + (rand() % 26);
        } else if (r < 85) {
            start_color[i++] = '-';
        } else {
            start_color[i++] = '(';
            while (i < len - 1 && rand() % 5 != 0) {
                start_color[i++] = 'a' + (rand() % 26);
            }
            if (i < len) {
                start_color[i++] = ')';
            }
        }
    }
    start_color[len] = '\0';
}

void init_vars() {
    srand(time(NULL));
    memset(start_color, 0, sizeof(start_color));
    init_array();
    p = NULL;
}