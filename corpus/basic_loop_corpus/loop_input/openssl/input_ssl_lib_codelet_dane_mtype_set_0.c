#include <stdio.h>
#include <inttypes.h>

typedef struct evp_md_st EVP_MD;

struct dane_ctx_st {
    const EVP_MD **mdevp;
    uint8_t *mdord;
    uint8_t mdmax;
    unsigned long flags;
};

static const int DATA_SIZE = 131072; // 128KB of data

// Define a complete definition for EVP_MD to avoid incomplete type errors
struct evp_md_st {
    int dummy; // Placeholder to make type complete
};

static EVP_MD evp_md_storage[DATA_SIZE];
static uint8_t mdord_storage[DATA_SIZE];

// Declare the external variables
struct dane_ctx_st *dctx;
uint8_t mtype;
int i;
EVP_MD **mdevp;
uint8_t *mdord;

void init_vars() {
    // Allocate and initialize the dane_ctx_st structure
    static struct dane_ctx_st ctx_instance;
    dctx = &ctx_instance;

    // Initialize array of EVP_MD pointers (non-const storage)
    static EVP_MD *mdevp_storage[DATA_SIZE];
    mdevp = mdevp_storage;

    // Point mdord to our preallocated storage
    mdord = mdord_storage;

    // Set loop bounds to ensure valid access within DATA_SIZE
    dctx->mdmax = DATA_SIZE / 2; // Ensure there's room: from mdmax+1 to mtype-1
    mtype = DATA_SIZE - 1;        // Keep under DATA_SIZE to prevent overflow

    // Initialize the mdevp array with valid pointers
    for (int j = 0; j < DATA_SIZE; ++j) {
        mdevp_storage[j] = &evp_md_storage[j];
    }

    // Initialize mdord array
    for (int j = 0; j < DATA_SIZE; ++j) {
        mdord_storage[j] = (uint8_t)(j & 0xFF);
    }

    // Set other context fields
    dctx->flags = 0;
}