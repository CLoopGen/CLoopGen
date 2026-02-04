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

typedef struct cipher_order_st {
    const SSL_CIPHER *cipher;
    int active;
    int dead;
    struct cipher_order_st *next;
    struct cipher_order_st *prev;
} CIPHER_ORDER;

#define DATA_SIZE 8192

SSL_CIPHER ssl_cipher_data[DATA_SIZE];
CIPHER_ORDER co_list[DATA_SIZE];

int i;
int co_list_num = DATA_SIZE;

void init_vars() {
    for (int j = 0; j < DATA_SIZE; j++) {
        ssl_cipher_data[j].valid = j;
        ssl_cipher_data[j].name = "TEST";
        ssl_cipher_data[j].stdname = "STDTEST";
        ssl_cipher_data[j].id = 0x1000 + j;
        ssl_cipher_data[j].algorithm_mkey = 1;
        ssl_cipher_data[j].algorithm_auth = 2;
        ssl_cipher_data[j].algorithm_enc = 3;
        ssl_cipher_data[j].algorithm_mac = 4;
        ssl_cipher_data[j].min_tls = 0;
        ssl_cipher_data[j].max_tls = 1;
        ssl_cipher_data[j].min_dtls = -1;
        ssl_cipher_data[j].max_dtls = 1;
        ssl_cipher_data[j].algo_strength = 0x80;
        ssl_cipher_data[j].algorithm2 = 0;
        ssl_cipher_data[j].strength_bits = 128;
        ssl_cipher_data[j].alg_bits = 128;
        
        co_list[j].cipher = &ssl_cipher_data[j];
        co_list[j].active = 1;
        co_list[j].dead = 0;
        co_list[j].next = NULL;
        co_list[j].prev = NULL;
    }
    
    co_list[0].prev = NULL;
    co_list[0].next = &co_list[1];
    co_list[DATA_SIZE - 1].prev = &co_list[DATA_SIZE - 2];
    co_list[DATA_SIZE - 1].next = NULL;
}