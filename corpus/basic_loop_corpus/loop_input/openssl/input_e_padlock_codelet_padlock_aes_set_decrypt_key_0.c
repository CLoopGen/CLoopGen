#include <stdio.h>
#include <inttypes.h>

struct aes_key_st {
    unsigned int rd_key[60];
    int rounds;
};

typedef struct aes_key_st AES_KEY;

typedef unsigned int u32;

AES_KEY *key;
u32 *rk;
int i;
int j;
u32 temp;

static u32 rk_buffer[1024];
static AES_KEY key_instance;

void init_vars() {
    key = &key_instance;
    rk = rk_buffer;

    key->rounds = 10;  // Standard AES-128 rounds

    int total_elements = 4 * (key->rounds + 1);  // Match typical expanded key size: 4*(Nk + 6 + 1) -> for Nk=4, rounds=10, we get 44
    for (int idx = 0; idx < total_elements; ++idx) {
        rk[idx] = idx * 0xdeadbeefU + 1;
    }

    // Ensure j is set to valid index: we are swapping elements at positions i and j, stepping by 4
    // The loop uses i < j with i += 4, j -= 4, so j must start at total_elements - 4 to be safe
    // But original loop sets j = 4 * rounds -> 40 for rounds=10, which is less than total_elements (44)
    // So we keep rounds=10 to make j=40, and ensure array has at least 44 elements -> we have 1024, safe.
}