#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
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

#define TOTAL_DATA_SIZE (512 * 1024) // ~512KB of input data
#define N_RECS_MAX 32

unsigned char global_input_data[TOTAL_DATA_SIZE];

void init_vars() {
    n_recs = N_RECS_MAX;
    recs = calloc(n_recs, sizeof(TLS_RL_RECORD));
    if (!recs) exit(1);

    for (size_t i = 0; i < n_recs; i++) {
        recs[i].rec_version = 0x0303;
        recs[i].type = 23;
        recs[i].length = 16384;
        recs[i].orig_len = 16384;
        recs[i].off = 0;
        recs[i].epoch = 0;
        memset(recs[i].seq_num, 0, 8);
        size_t offset = i * (TOTAL_DATA_SIZE / n_recs);
        recs[i].input = &global_input_data[offset];
        recs[i].data = NULL;
        recs[i].comp = NULL;
    }

    memset(global_input_data, 0xAA, TOTAL_DATA_SIZE);

    for (int i = 0; i < 32; i++) {
        data[i] = NULL;
    }

    ctr = 0;
}