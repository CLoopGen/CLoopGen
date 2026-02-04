#include <stdio.h>
#include <inttypes.h>

typedef unsigned long Hashseq;

Hashseq hashprobe = 0;
char coded[17] = "abcdefghijklmnop";
int len = 17;
int i = 0;

void init_vars() {
    // No additional initialization needed beyond static initializers
    // All variables are already initialized at file scope with valid values
    // Array size matches declared size, len is set to array length to prevent out-of-bounds access
}