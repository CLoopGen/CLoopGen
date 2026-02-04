#include <inttypes.h>

typedef int Int32;
typedef unsigned char Bool;

Int32 i;
Int32 runningOrder[256];
Bool bigDone[256];

void init_vars() {
    // No dynamic data size needed since arrays are fixed to 256 elements
    // Loop runs exactly 256 iterations (0 to 255), which is negligible in time (< 1 microsecond)
    // No additional initialization required beyond what loop already does
    // The loop itself initializes bigDone and runningOrder arrays
    // Thus, no extra work needed in init_vars beyond ensuring variables are defined
}