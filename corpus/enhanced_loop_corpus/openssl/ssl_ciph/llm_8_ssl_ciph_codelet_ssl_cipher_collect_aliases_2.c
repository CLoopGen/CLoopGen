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
    for (i = 0; i < num_of_group_aliases; i += 2) {
        uint32_t algorithm_mkey = cipher_aliases[i].algorithm_mkey;
        uint32_t algorithm_auth = cipher_aliases[i].algorithm_auth;
        uint32_t algorithm_enc = cipher_aliases[i].algorithm_enc;
        uint32_t algorithm_mac = cipher_aliases[i].algorithm_mac;
        
        // Unroll the condition checks into a single combined expression to reduce branching
        if ((algorithm_mkey == 0 || (algorithm_mkey & mask_mkey)) &&
            (algorithm_auth == 0 || (algorithm_auth & mask_auth)) &&
            (algorithm_enc == 0 || (algorithm_enc & mask_enc)) &&
            (algorithm_mac == 0 || (algorithm_mac & mask_mac))) {
            *ca_curr = (SSL_CIPHER *)(cipher_aliases + i);
            ca_curr++;
        }
        
        // Second iteration of unrolled loop (if within bounds)
        if (i + 1 < num_of_group_aliases) {
            algorithm_mkey = cipher_aliases[i + 1].algorithm_mkey;
            algorithm_auth = cipher_aliases[i + 1].algorithm_auth;
            algorithm_enc = cipher_aliases[i + 1].algorithm_enc;
            algorithm_mac = cipher_aliases[i + 1].algorithm_mac;

            if ((algorithm_mkey == 0 || (algorithm_mkey & mask_mkey)) &&
                (algorithm_auth == 0 || (algorithm_auth & mask_auth)) &&
                (algorithm_enc == 0 || (algorithm_enc & mask_enc)) &&
                (algorithm_mac == 0 || (algorithm_mac & mask_mac))) {
                *ca_curr = (SSL_CIPHER *)(cipher_aliases + i + 1);
                ca_curr++;
            }
        }
    }
}
