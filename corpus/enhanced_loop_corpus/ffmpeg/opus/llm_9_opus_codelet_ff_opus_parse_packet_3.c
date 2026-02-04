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

extern OpusPacket *pkt;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    pkt->frame_offset[0] = 0;
    for (i = 0; i < pkt->frame_count - 1; i++)
        pkt->frame_offset[i + 1] = pkt->frame_offset[i] + pkt->frame_size[i];
}
