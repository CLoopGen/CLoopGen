#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

char response[41];
char chksum[9];
int i;

void init_vars() {
    for (int j = 0; j < 41; j++) {
        response[j] = (char)(j * 37); // Arbitrary initialization to avoid undefined behavior
    }
    for (int j = 0; j < 9; j++) {
        chksum[j] = 0;
    }
    i = 0;
}