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

TLS_RL_RECORD *rec;
size_t end;

static unsigned char *data_buffer;
static TLS_RL_RECORD rec_storage;

void init_vars() {
    const size_t buffer_size = 512 * 1024; // 512 KB of data

    data_buffer = (unsigned char *)calloc(buffer_size, sizeof(unsigned char));
    if (!data_buffer) {
        exit(1);
    }

    // Initialize trailing portion to zero to allow loop to scan backwards
    size_t non_zero_end = buffer_size - 100;
    memset(data_buffer, 1, non_zero_end);
    memset(data_buffer + non_zero_end, 0, buffer_size - non_zero_end);

    rec_storage.length = buffer_size - 1; // Ensure we don't access out of bounds
    rec_storage.data = data_buffer;

    rec = &rec_storage;
    end = rec->length;
}