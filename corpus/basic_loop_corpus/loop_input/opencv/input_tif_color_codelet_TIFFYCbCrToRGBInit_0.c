#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char TIFFRGBValue;

TIFFRGBValue *clamptab;
int i;

void init_vars() {
    clamptab = (TIFFRGBValue*)malloc(256 * sizeof(TIFFRGBValue));
    if (!clamptab) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}

void loop();