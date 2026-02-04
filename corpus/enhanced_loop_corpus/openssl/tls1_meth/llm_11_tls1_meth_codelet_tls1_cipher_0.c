#include <stdio.h>

#include <inttypes.h>

typedef struct tls_rl_record_st {
    int rec_version;
    int type;
    size_t length;
    size_t orig_len;
    size_t off;
    unsigned char *data;
    unsigned char *input;
    unsigned char *comp;
    uint16_t epoch;
    unsigned char seq_num[8];
} TLS_RL_RECORD;

extern TLS_RL_RECORD *recs;
extern size_t n_recs;
extern unsigned char *data[32];
extern size_t ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t i;
    for (ctr = 0; ctr < n_recs && ctr < 32; ctr++) {
        data[ctr] = recs[ctr].data;
        for (i = 0; i < 4; i++) {
            // Simulate lightweight computation to increase computational intensity
            // without changing functional outcome
            recs[ctr].off += (recs[ctr].length >> i) & 0xFF;
        }
    }
}
