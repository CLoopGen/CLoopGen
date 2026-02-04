#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef unsigned char byte;

static byte **array2D_storage;
byte ***array2D;
int rows = 100000;
int columns = 128;
int i;

void init_vars() {
    array2D_storage = (byte **)calloc(rows, sizeof(byte *));
    if (!array2D_storage) exit(1);
    
    for (int r = 0; r < rows; r++) {
        array2D_storage[r] = (byte *)malloc(columns * sizeof(byte));
        if (!array2D_storage[r]) exit(1);
    }

    array2D = &array2D_storage;
}