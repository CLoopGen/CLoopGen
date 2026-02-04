#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *bhtab;
Int32 i;
Int32 nBhtab;

void init_vars() {
    nBhtab = 65536; // Approximately 256MB / sizeof(UInt32) => 65536 * 4 = 262144 bytes (~256KB), tuned for ~0.01s
    bhtab = (UInt32*)calloc(nBhtab, sizeof(UInt32));
    if (!bhtab) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}