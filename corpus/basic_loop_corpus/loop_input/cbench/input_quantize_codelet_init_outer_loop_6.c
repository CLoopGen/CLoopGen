#include <inttypes.h>

typedef double FLOAT8;

int b;
FLOAT8 en[3];

void init_vars() {
    // No dynamic data size adjustment needed since en is fixed size (3 elements)
    // The loop in this case runs only 3 iterations, so no large data initialization required
    // External variable 'b' is used as loop counter, initialized within loop
    // Array 'en' is of fixed size 3, already defined with static storage
}