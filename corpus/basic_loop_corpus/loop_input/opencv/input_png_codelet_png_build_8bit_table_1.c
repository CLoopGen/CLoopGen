#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef unsigned char png_byte;
typedef png_byte *png_bytep;

unsigned int i;
static png_byte table_data[256];
png_bytep table = table_data;

void init_vars() {
    i = 0;
}