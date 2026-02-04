#include <stdio.h>

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

extern  SSL_CIPHER cipher_aliases[];
extern int num_of_group_aliases;
extern  SSL_CIPHER **ca_curr;
extern int i;
extern uint32_t mask_mkey;
extern uint32_t mask_auth;
extern uint32_t mask_enc;
extern uint32_t mask_mac;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < (num_of_group_aliases + 3) / 4; outer++) {
        for (int inner = 0; inner < 4; inner++) {
            int i = outer * 4 + inner;
            if (i >= num_of_group_aliases) break;

            uint32_t algorithm_mkey = cipher_aliases[i].algorithm_mkey;
            uint32_t algorithm_auth = cipher_aliases[i].algorithm_auth;
            uint32_t algorithm_enc = cipher_aliases[i].algorithm_enc;
            uint32_t algorithm_mac = cipher_aliases[i].algorithm_mac;

            if (algorithm_mkey && ((algorithm_mkey & mask_mkey) == 0))
                continue;
            if (algorithm_auth && ((algorithm_auth & mask_auth) == 0))
                continue;
            if (algorithm_enc && ((algorithm_enc & mask_enc) == 0))
                continue;
            if (algorithm_mac && ((algorithm_mac & mask_mac) == 0))
                continue;

            *ca_curr = (SSL_CIPHER *)(cipher_aliases + i);
            ca_curr++;
        }
    }
}
