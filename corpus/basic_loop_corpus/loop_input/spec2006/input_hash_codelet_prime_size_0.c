#include <inttypes.h>

typedef int int32;

int32 prime[] = {0}; // Provide a weak definition with initializer to avoid redefinition issues

static int32 prime_data[65536];
int32 size;
int32 i;

void init_vars() {
    size = 65536;
    for (int j = 0; j < 65535; j++) {
        prime_data[j] = j + 1;
    }
    prime_data[65535] = -1;
    
    __builtin_memcpy(prime, prime_data, sizeof(prime_data));
}