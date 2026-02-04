#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    for (int i = 0; i < 4095; i++) {
        start_color[i] = 'a' + (i % 26);
        if (i % 128 == 0 && i + 1 < 4095) {
            start_color[i] = '(';
            i++;
            while (i < 4095 && start_color[i] != ')') {
                start_color[i] = 'a' + (i % 26);
                i++;
            }
            if (i < 4095) {
                start_color[i] = ')';
            } else {
                break;
            }
        }
    }
    start_color[4095] = '-';
}