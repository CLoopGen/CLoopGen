#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

char start_color[262144] __attribute__((aligned(4096)));
char *p;

void init_vars() {
    size_t size = sizeof(start_color);
    
    for (size_t i = 0; i < size - 1; i++) {
        int r = rand() % 100;
        if (r < 70) {
            start_color[i] = 'a' + (rand() % 26);
        } else if (r < 85) {
            start_color[i] = '(';
            i++;
            while (i < size - 1) {
                if (rand() % 15 == 0) {
                    start_color[i] = ')';
                    break;
                }
                start_color[i] = 'a' + (rand() % 26);
                i++;
            }
            if (i >= size - 1) break;
        } else {
            start_color[i] = '-';
            break;
        }
    }
    
    if (start_color[size - 1] != '-' && start_color[size - 1] != '\x00') {
        start_color[size - 1] = '\x00';
    }
}