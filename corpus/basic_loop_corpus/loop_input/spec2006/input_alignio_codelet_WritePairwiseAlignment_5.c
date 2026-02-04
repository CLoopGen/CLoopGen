#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

char buf1[61];
int count1;
int rawcount1;
int apos;

void init_vars() {
    count1 = 61;
    rawcount1 = 0;
    apos = 0;

    for (int i = 0; i < count1; i++) {
        buf1[i] = 'A' + (i % 26);
    }

    buf1[5] = ' ';
    buf1[10] = '.';
    buf1[15] = '_';
    buf1[20] = '-';
    buf1[25] = '~';
}