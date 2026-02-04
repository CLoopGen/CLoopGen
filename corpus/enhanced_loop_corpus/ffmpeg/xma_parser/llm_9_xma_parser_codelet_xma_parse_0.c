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
    for (packet = 0; packet < nb_packets && s->skip_packets > -10; packet++) {
        if (s->skip_packets == 0) {
            int index = packet * 2048;
            duration += (buf[index] << 7); // Equivalent to *128, using bit shift
            s->skip_packets = (buf[index + 3] & 0xFF) + 1; // Masking byte value explicitly
        }
        s->skip_packets--;
        // Add extra computation to increase intensity
        duration += (buf[packet * 2048 + 1] & 1) ? 64 : 0;
    }
}
