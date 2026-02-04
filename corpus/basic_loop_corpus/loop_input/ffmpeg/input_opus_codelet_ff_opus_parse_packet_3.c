#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

enum OpusMode {
    OPUS_MODE_SILK,
    OPUS_MODE_HYBRID,
    OPUS_MODE_CELT,
    OPUS_MODE_NB
};

enum OpusBandwidth {
    OPUS_BANDWIDTH_NARROWBAND,
    OPUS_BANDWIDTH_MEDIUMBAND,
    OPUS_BANDWIDTH_WIDEBAND,
    OPUS_BANDWIDTH_SUPERWIDEBAND,
    OPUS_BANDWIDTH_FULLBAND,
    OPUS_BANDWITH_NB
};

typedef struct OpusPacket {
    int packet_size;
    int data_size;
    int code;
    int stereo;
    int vbr;
    int config;
    int frame_count;
    int frame_offset[48];
    int frame_size[48];
    int frame_duration;
    enum OpusMode mode;
    enum OpusBandwidth bandwidth;
} OpusPacket;

OpusPacket *pkt;
int i;

void init_vars() {
    pkt = (OpusPacket*)malloc(sizeof(OpusPacket));
    if (!pkt) exit(1);

    pkt->packet_size = 1024 * 1024; // ~1MB packet size
    pkt->data_size = pkt->packet_size;
    pkt->code = 0;
    pkt->stereo = 1;
    pkt->vbr = 1;
    pkt->config = 3;
    pkt->frame_count = 47; // Max safe value to avoid out-of-bounds in loop using frame_offset[48]
    pkt->frame_duration = 20;

    pkt->mode = OPUS_MODE_HYBRID;
    pkt->bandwidth = OPUS_BANDWIDTH_FULLBAND;

    // Initialize frame_size with non-zero values to simulate realistic data
    for (int j = 0; j < 48; j++) {
        pkt->frame_size[j] = 160 + (j % 97); // Small frames, ~160-256 samples each
    }

    // Initialize first frame offset
    pkt->frame_offset[0] = 0;

    // Pre-initialize remaining offsets to zero (will be recomputed in loop)
    for (int j = 1; j < 48; j++) {
        pkt->frame_offset[j] = 0;
    }
}