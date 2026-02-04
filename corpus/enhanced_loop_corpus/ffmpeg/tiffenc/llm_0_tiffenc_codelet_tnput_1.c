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
    for (int outer = 0; outer < n; outer++) {
        for (int inner = 0; inner < type_sizes2[type]; inner++) {
            int index = outer * type_sizes2[type] + inner;
            *(*p)++ = val[index ^ flip];
        }
    }
}
