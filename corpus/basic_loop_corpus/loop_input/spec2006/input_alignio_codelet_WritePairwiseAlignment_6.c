#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

char buf2[1 << 20];
int count2;
int rawcount2;
int apos;

void init_vars() {
    count2 = sizeof(buf2);
    rawcount2 = 0;
    apos = 0;

    for (int i = 0; i < count2; i++) {
        int r = rand() % 128;
        if (r < 0) r = -r;
        if (r < 128) {
            char c = (char)r;
            if (!((c == ' ') || (c == '.') || (c == '_') || (c == '-') || (c == '~'))) {
                buf2[i] = c;
            } else {
                buf2[i] = 'a'; // arbitrary non-matching char that still triggers condition
            }
        } else {
            buf2[i] = 'a';
        }
    }
}