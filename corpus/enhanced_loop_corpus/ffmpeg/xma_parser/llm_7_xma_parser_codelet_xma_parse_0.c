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
    int local_skip = s->skip_packets;
    int temp_duration = duration;
    for (packet = 0; packet < nb_packets; packet++) {
        if (local_skip <= 0) {
            temp_duration += buf[packet * 2048] * 128;
            local_skip = buf[packet * 2048 + 3] + 1;
        }
        local_skip--;
    }
    s->skip_packets = local_skip;
    duration = temp_duration;
}
