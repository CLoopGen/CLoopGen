#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct AVProbeData {
    const char *filename;
    unsigned char *buf;
    int buf_size;
    const char *mime_type;
} AVProbeData;

static unsigned char *data_buf;
static AVProbeData probe_data;

AVProbeData *p = &probe_data;
uint64_t code = 0;
int i = 0;
int valid_psc = 0;
int invalid_psc = 0;
int res_change = 0;
int src_fmt = 0;
int last_src_fmt = 0;
int last_gn = 0;
int tr = 0;
int last_tr = 0;

void init_vars() {
    const size_t input_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime estimate

    data_buf = (unsigned char *)malloc(input_size);
    if (!data_buf) {
        exit(1);
    }

    // Initialize buffer with pseudo-pattern to trigger various conditions in loop
    for (size_t idx = 0; idx < input_size; idx++) {
        data_buf[idx] = (unsigned char)(idx % 256);
    }

    // Setup probe_data
    probe_data.filename = "dummy.bin";
    probe_data.buf = data_buf;
    probe_data.buf_size = (int)input_size;
    probe_data.mime_type = "application/octet-stream";

    // Initialize state variables
    code = 0;
    valid_psc = 0;
    invalid_psc = 0;
    res_change = 0;
    src_fmt = 0;
    last_src_fmt = 1; // ensure valid initial comparison
    last_gn = 0;
    tr = 0;
    last_tr = 0;
}