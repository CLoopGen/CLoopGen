#include <stdio.h>

#include <inttypes.h>

typedef unsigned char UChar;

typedef struct {
    UChar b[8];
} UInt64;

typedef unsigned int UInt32;

typedef int Int32;

extern UInt64 *n;
extern UInt32 rem;
extern UInt32 tmp;
extern Int32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    UInt32 temp_array[8];
    for (i = 7; i >= 0; i--) {
        tmp = rem * 256 + n->b[i];
        temp_array[i] = tmp / 10;
        rem = tmp % 10;
    }
    for (i = 7; i >= 0; i--) {
        n->b[i] = temp_array[i];
    }
}
