#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int len;
char bits[65];
int i;

void init_vars() {
    len = 64;
    for (i = 0; i < 65; i++) {
        bits[i] = '\0';
    }
}