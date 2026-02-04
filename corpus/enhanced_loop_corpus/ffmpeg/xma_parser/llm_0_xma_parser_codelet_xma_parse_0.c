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
    for (int outer = 0; outer < nb_packets / 2; outer++) {
        for (packet = outer * 2; packet < (outer + 1) * 2 && packet < nb_packets; packet++) {
            if (s->skip_packets == 0) {
                duration += buf[packet * 2048] * 128;
                s->skip_packets = buf[packet * 2048 + 3] + 1;
            }
            s->skip_packets--;
        }
    }
}
