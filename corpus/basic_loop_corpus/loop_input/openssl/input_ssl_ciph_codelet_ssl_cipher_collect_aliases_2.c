#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

struct ssl_cipher_st {
    uint32_t valid;
    const char *name;
    const char *stdname;
    uint32_t id;
    uint32_t algorithm_mkey;
    uint32_t algorithm_auth;
    uint32_t algorithm_enc;
    uint32_t algorithm_mac;
    int min_tls;
    int max_tls;
    int min_dtls;
    int max_dtls;
    uint32_t algo_strength;
    uint32_t algorithm2;
    int32_t strength_bits;
    uint32_t alg_bits;
};

typedef struct ssl_cipher_st SSL_CIPHER;

#define NUM_CIPHERS 8192

SSL_CIPHER cipher_aliases[NUM_CIPHERS];
int num_of_group_aliases = NUM_CIPHERS;
SSL_CIPHER **ca_curr;
int i;
uint32_t mask_mkey = 0xFFFFFFFF;
uint32_t mask_auth = 0xFFFFFFFF;
uint32_t mask_enc = 0xFFFFFFFF;
uint32_t mask_mac = 0xFFFFFFFF;

void init_vars() {
    ca_curr = (SSL_CIPHER**)malloc(NUM_CIPHERS * sizeof(SSL_CIPHER*));
    if (!ca_curr) {
        exit(1);
    }
    for (int j = 0; j < NUM_CIPHERS; j++) {
        cipher_aliases[j].valid = 1;
        cipher_aliases[j].name = "TEST_CIPHER";
        cipher_aliases[j].stdname = "TEST_STDNAME";
        cipher_aliases[j].id = j;
        cipher_aliases[j].algorithm_mkey = (j % 2) ? 0x1 : 0x2;
        cipher_aliases[j].algorithm_auth = (j % 3) ? 0x4 : 0x8;
        cipher_aliases[j].algorithm_enc = (j % 5) ? 0x10 : 0x20;
        cipher_aliases[j].algorithm_mac = (j % 7) ? 0x40 : 0x80;
        cipher_aliases[j].min_tls = 0;
        cipher_aliases[j].max_tls = 1;
        cipher_aliases[j].min_dtls = -1;
        cipher_aliases[j].max_dtls = 1;
        cipher_aliases[j].algo_strength = 0x100;
        cipher_aliases[j].algorithm2 = 0;
        cipher_aliases[j].strength_bits = 128;
        cipher_aliases[j].alg_bits = 128;
    }
}