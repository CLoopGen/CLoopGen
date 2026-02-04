#include <stddef.h>
#include <inttypes.h>

typedef struct evp_pkey_st EVP_PKEY;

EVP_PKEY *key[4];
size_t i;

void init_vars() {
    // No additional initialization needed for nulling pointers
    // Array size is fixed at 4, so loop runs exactly 4 times
    // This is sufficient for the required timing given the simplicity of the operation
}