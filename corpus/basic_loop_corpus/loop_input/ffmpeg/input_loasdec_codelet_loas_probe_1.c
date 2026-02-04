#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

int max_frames;
int first_frames;
int fsize;
int frames;

uint8_t *buf0;
uint8_t *buf2;
uint8_t *buf;
uint8_t *end;

static uint8_t *data_buffer;

void init_vars() {
    size_t data_size = 64 * 1024 * 1024; // 64 MB for ~0.01 sec runtime target
    data_buffer = (uint8_t*)aligned_alloc(32, data_size);
    if (!data_buffer) exit(1);

    memset(data_buffer, 0, data_size);

    // Initialize packet-like structures periodically to simulate valid headers
    int packet_interval = 100;
    int header_start = 0;
    while (header_start + 7 <= data_size) {
        // Write valid header: sync word with (header >> 13) == 695 and fsize >= 7
        uint32_t raw_header = 695 << 13; // sync pattern
        raw_header |= 10; // fsize - 3 = 10 => fsize = 13
        data_buffer[header_start + 0] = (raw_header >> 16) & 0xFF;
        data_buffer[header_start + 1] = (raw_header >> 8) & 0xFF;
        data_buffer[header_start + 2] = raw_header & 0xFF;
        // Fill rest of frame with non-header data
        memset(data_buffer + header_start + 3, 0, 10);
        header_start += packet_interval;
    }

    buf0 = data_buffer;
    buf = data_buffer;
    buf2 = data_buffer;
    end = data_buffer + data_size;

    max_frames = 0;
    first_frames = 0;
    fsize = 0;
    frames = 0;
}