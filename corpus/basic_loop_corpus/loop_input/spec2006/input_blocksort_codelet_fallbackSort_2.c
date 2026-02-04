#include <inttypes.h>

typedef int Int32;

Int32 ftab[257];
Int32 i;

void init_vars() {
    // No additional initialization needed beyond zero-initialization of ftab
    // The loop will handle setting ftab elements to 0
    // Ensure i is within valid range for subsequent loop usage
    i = 0;
}