#include <stdio.h>
#include <inttypes.h>

typedef unsigned char TIFFRGBValue;

TIFFRGBValue *clamptab;
int i;

#define CLAMPTAB_SIZE (16 << 20)  // 16 MB of data

static TIFFRGBValue clamptab_storage[CLAMPTAB_SIZE];

void init_vars() {
    clamptab = clamptab_storage;
}