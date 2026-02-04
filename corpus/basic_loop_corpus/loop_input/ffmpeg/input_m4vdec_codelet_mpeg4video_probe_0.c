#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVProbeData {
    const char *filename;
    unsigned char *buf;
    int buf_size;
    const char *mime_type;
} AVProbeData;

AVProbeData *probe_packet;
uint32_t temp_buffer;
int VO;
int VOL;
int VOP;
int VISO;
int res;
int res_main;
int i;

static unsigned char *generated_buf;
static const char *default_filename = "probe_file.dat";
static const char *default_mime_type = "application/octet-stream";

void init_vars() {
    const size_t data_size = 64 << 20; // 64 MB of input data for sufficient runtime (~0.01 sec on modern CPU)

    generated_buf = (unsigned char *)calloc(data_size, sizeof(unsigned char));
    if (!generated_buf) {
        fprintf(stderr, "Failed to allocate buffer\n");
        exit(1);
    }

    // Initialize with pseudo-random but deterministic byte pattern
    for (size_t j = 0; j < data_size; j++) {
        generated_buf[j] = (unsigned char)((j * j + 3) % 256);
    }

    probe_packet = (AVProbeData *)malloc(sizeof(AVProbeData));
    if (!probe_packet) {
        fprintf(stderr, "Failed to allocate probe_packet\n");
        exit(1);
    }

    probe_packet->filename = default_filename;
    probe_packet->buf = generated_buf;
    probe_packet->buf_size = (int)data_size;
    probe_packet->mime_type = default_mime_type;

    temp_buffer = 0;
    VO = 0;
    VOL = 0;
    VOP = 0;
    VISO = 0;
    res = 0;
    res_main = 0;
    i = 0;
}