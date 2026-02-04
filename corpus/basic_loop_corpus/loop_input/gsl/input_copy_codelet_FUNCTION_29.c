#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

size_t M = 10000;
size_t N = 20000;
size_t i;
size_t j;

void init_vars() {
    // No dynamic initialization needed for scalar loop bounds
    // Values are statically initialized above to ensure safe loop execution
}