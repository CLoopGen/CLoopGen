#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t f[2][6] = {
    {100000, 200000, 300000, 400000, 500000, 600000},
    {600000, 500000, 400000, 300000, 200000, 100000}
};

int i;

void init_vars() {
    // No additional initialization needed; static array and scalar already defined
    // Loop bounds in loop() are fixed (i from 5 down to 1), so no risk of OOB access
    // Array sizes match the indexed range: f[0][i] with i=5 accesses f[0][5], which is valid
}