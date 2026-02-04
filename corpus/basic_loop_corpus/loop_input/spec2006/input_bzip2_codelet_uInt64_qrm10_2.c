#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char UChar;

typedef struct {
    UChar b[8];
} UInt64;

typedef unsigned int UInt32;
typedef int Int32;

UInt64 *n;
UInt32 rem;
UInt32 tmp;
Int32 i;

void init_vars() {
    n = (UInt64*)aligned_alloc(32, 1048576 * sizeof(UInt64));
    if (!n) exit(1);

    for (int idx = 0; idx < (1048576 / 8); idx++) {
        n[idx].b[0] = (UChar)(idx % 256);
        n[idx].b[1] = (UChar)((idx >> 8) % 256);
        n[idx].b[2] = (UChar)((idx >> 16) % 256);
        n[idx].b[3] = (UChar)((idx >> 24) % 256);
        n[idx].b[4] = (UChar)((idx + 100) % 256);
        n[idx].b[5] = (UChar)((idx + 200) % 256);
        n[idx].b[6] = (UChar)((idx + 50) % 256);
        n[idx].b[7] = (UChar)((idx + 150) % 256);
    }

    rem = 7;
    tmp = 0;
    i = 0;
}