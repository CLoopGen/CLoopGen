#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    for (int i = 0; i < 4095; i++) {
        start_color[i] = 'a' + (i % 26);
        if (i % 128 == 0 && i > 0) {
            start_color[i - 1] = '(';
            int j = i;
            while (j < 4095 && j < i + 64) {
                start_color[j++] = 'x';
            }
            if (j < 4095) {
                start_color[j] = ')';
            } else {
                break;
            }
            i = j;
        }
    }
    start_color[4095] = '\0';
}