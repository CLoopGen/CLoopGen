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


extern  uint8_t type_sizes2[14];
extern uint8_t **p;
extern int n;
extern  uint8_t *val;
extern enum TiffTypes type;
extern int flip;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (type >= 14 || type < TIFF_BYTE) return;
    for (i = 0; i < n * type_sizes2[type]; i++) {
        int index = i ^ flip;
        *(*p)++ = val[index];
    }
}
