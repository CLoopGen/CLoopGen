#include <inttypes.h>

typedef unsigned char UChar;
typedef int Int32;

UChar pos[6];
Int32 i;
Int32 nGroups;

void init_vars() {
    nGroups = 6; // Set nGroups to match the size of pos array to prevent out-of-bounds access
}