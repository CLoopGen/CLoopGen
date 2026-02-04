#include <stdio.h>
#include <inttypes.h>

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

UInt64 n_storage; 

void init_vars() {
    n = &n_storage;
    rem = 123456789U;
    tmp = 0;
    i = 0;

    for (int idx = 0; idx < 8; idx++) {
        n->b[idx] = (UChar)(idx * 17);
    }
}