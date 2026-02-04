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
    for (packet = 0; packet < nb_packets; packet++) {
        int skip_is_zero = (s->skip_packets == 0);
        duration += skip_is_zero * (buf[packet * 2048] * 128);
        s->skip_packets = skip_is_zero * (buf[packet * 2048 + 3] + 1) + (!skip_is_zero) * s->skip_packets;
        s->skip_packets--;
    }
}
