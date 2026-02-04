#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum TiffTypes {
    TIFF_BYTE = 1,
    TIFF_STRING,
    TIFF_SHORT,
    TIFF_LONG,
    TIFF_RATIONAL,
    TIFF_SBYTE,
    TIFF_UNDEFINED,
    TIFF_SSHORT,
    TIFF_SLONG,
    TIFF_SRATIONAL,
    TIFF_FLOAT,
    TIFF_DOUBLE,
    TIFF_IFD
};

uint8_t type_sizes2[14] = {
    0, // dummy for index 0
    1, // TIFF_BYTE
    1, // TIFF_STRING
    2, // TIFF_SHORT
    4, // TIFF_LONG
    8, // TIFF_RATIONAL (4+4)
    1, // TIFF_SBYTE
    1, // TIFF_UNDEFINED
    2, // TIFF_SSHORT
    4, // TIFF_SLONG
    8, // TIFF_SRATIONAL (4+4)
    4, // TIFF_FLOAT
    8, // TIFF_DOUBLE
    4  // TIFF_IFD
};

uint8_t **p;
uint8_t *val;
enum TiffTypes type;
int flip;
int i;
int n;

void init_vars() {
    type = TIFF_LONG;        
    n = (1 << 20);           
    flip = 0;                

    size_t data_size = n * type_sizes2[type];

    val = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!val) exit(1);

    uint8_t *buffer = (uint8_t*)calloc(data_size, sizeof(uint8_t));
    if (!buffer) exit(1);

    p = (uint8_t**)malloc(sizeof(uint8_t*));
    if (!p) exit(1);
    *p = buffer;

    for (size_t idx = 0; idx < data_size; idx++) {
        val[idx] = (uint8_t)(idx & 0xFF);
    }
}