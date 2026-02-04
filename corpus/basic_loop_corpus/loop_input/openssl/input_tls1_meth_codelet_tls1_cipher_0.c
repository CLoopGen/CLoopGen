#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

TLS_RL_RECORD *recs;
size_t n_recs;
unsigned char *data[32];
size_t ctr;

static unsigned char global_data_pool[1024 * 1024]; // 1MB pool for data storage

void init_vars() {
    n_recs = 32;
    ctr = 0;

    // Allocate and initialize recs array
    recs = (TLS_RL_RECORD *)calloc(n_recs, sizeof(TLS_RL_RECORD));
    if (!recs) exit(1);

    const size_t chunk_size = 32768; // 32KB per chunk
    for (size_t i = 0; i < n_recs; i++) {
        recs[i].rec_version = 0x0303;
        recs[i].type = 23;
        recs[i].length = chunk_size;
        recs[i].orig_len = chunk_size;
        recs[i].off = 0;
        recs[i].data = &global_data_pool[i * chunk_size];
        recs[i].input = recs[i].data;
        recs[i].comp = NULL;
        recs[i].epoch = 0;
        memset(recs[i].seq_num, 0, 8);

        // Initialize data with dummy values
        memset(recs[i].data, (int)(i + 1), chunk_size);
    }

    // Initialize data pointers to match recs[].data
    for (size_t i = 0; i < 32; i++) {
        data[i] = recs[i].data;
    }
}