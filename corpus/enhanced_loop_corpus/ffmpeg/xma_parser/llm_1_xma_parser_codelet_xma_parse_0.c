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
    if (nb_packets > 0) {
        packet = 0;
        for (; packet < nb_packets - 1; packet += 2) {
            if (s->skip_packets == 0) {
                duration += buf[packet * 2048] * 128;
                s->skip_packets = buf[packet * 2048 + 3] + 1;
            }
            s->skip_packets--;

            if (s->skip_packets == 0) {
                duration += buf[(packet + 1) * 2048] * 128;
                s->skip_packets = buf[(packet + 1) * 2048 + 3] + 1;
            }
            s->skip_packets--;
        }
        if (packet < nb_packets) {
            if (s->skip_packets == 0) {
                duration += buf[packet * 2048] * 128;
                s->skip_packets = buf[packet * 2048 + 3] + 1;
            }
            s->skip_packets--;
        }
    }
}
