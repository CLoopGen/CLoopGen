#include <stdio.h>
#include <inttypes.h>

typedef int Int32;
typedef unsigned char UChar;

Int32 nGroups = 6;
UChar pos[6];
UChar v;

void init_vars() {
    nGroups = 6;
    for (int i = 0; i < 6; i++) {
        pos[i] = 0;
    }
    v = 0;
}

void loop();