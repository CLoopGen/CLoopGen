#include <inttypes.h>

int count;
unsigned int parts[16];

void init_vars() {
    // No additional initialization needed beyond zeroing parts in loop
    // Array size is fixed at 16, which fits within loop bound: ((8*8)/8)*2 = 16
}