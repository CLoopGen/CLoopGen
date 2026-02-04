#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct XMAParserContext {
    int skip_packets;
} XMAParserContext;

extern  uint8_t *buf;
extern XMAParserContext *s;
extern int duration;
extern int packet;
extern int nb_packets;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_duration = duration;
    for (packet = 0; packet < nb_packets; packet++) {
        int skip_val = s->skip_packets;
        if (skip_val == 0) {
            temp_duration += buf[packet * 2048] * 128;
            skip_val = buf[packet * 2048 + 3] + 1;
        }
        s->skip_packets = skip_val - 1;
    }
    duration = temp_duration;
}
