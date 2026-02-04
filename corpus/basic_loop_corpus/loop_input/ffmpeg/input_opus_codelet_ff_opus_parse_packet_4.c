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
int frame_bytes;
int i;

void init_vars() {
    pkt = (OpusPacket*)calloc(1, sizeof(OpusPacket));
    if (!pkt) exit(1);

    pkt->frame_count = 47;
    pkt->frame_duration = 20;
    pkt->mode = OPUS_MODE_HYBRID;
    pkt->bandwidth = OPUS_BANDWIDTH_SUPERWIDEBAND;
    pkt->frame_size[0] = 150;
    pkt->frame_offset[0] = 0;

    for (int j = 1; j < pkt->frame_count; j++) {
        pkt->frame_size[j] = 0;
        pkt->frame_offset[j] = 0;
    }

    frame_bytes = 150;
    i = 0;
}