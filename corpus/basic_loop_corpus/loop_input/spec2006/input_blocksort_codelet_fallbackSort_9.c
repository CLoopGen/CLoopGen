#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int UInt32;
typedef int Int32;

UInt32 *bhtab;
Int32 nblock;
Int32 i;

void init_vars() {
    nblock = 1000000; // ensures offset into bhtab is safe
    size_t total_bits = (nblock + 2 * 31 + 1) >> 5;
    total_bits += 32; // extra padding to prevent overflow in last access
    size_t num_words = total_bits + 100;
    bhtab = (UInt32*)calloc(num_words, sizeof(UInt32));
    if (!bhtab) {
        exit(1);
    }
}