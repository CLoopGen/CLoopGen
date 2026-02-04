#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char start_color[4096];
char *p;

void init_vars() {
    for (int i = 0; i < 4095; i++) {
        if (i % 128 == 0 && i > 0) {
            start_color[i] = '(';
            int j = i + 1;
            while (j < 4095 && j < i + 64) {
                if (rand() % 10 == 0) {
                    start_color[j] = ')';
                    break;
                }
                start_color[j] = 'a' + (rand() % 26);
                j++;
            }
            if (j == 4095) {
                start_color[4094] = ')';
            }
            i = j < 4095 ? j : 4095;
        } else {
            start_color[i] = 'a' + (rand() % 26);
        }
    }
    start_color[4095] = '\x00';
    p = start_color;
}