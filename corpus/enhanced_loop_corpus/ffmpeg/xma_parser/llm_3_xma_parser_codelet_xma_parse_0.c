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
    // Variant 2: Indirect Memory Access via Index Array
    // Simulate indirect access using a precomputed index array to access buf elements.
    // This mimics scenarios where data layout is non-linear or scattered.
    int *indices = (int*)malloc(nb_packets * sizeof(int));
    if (!indices) return; // Handle malloc failure gracefully
    for (int i = 0; i < nb_packets; i++) {
        indices[i] = i * 2048;
    }
    for (packet = 0; packet < nb_packets; packet++) {
        int base = indices[packet];
        if (s->skip_packets == 0) {
            duration += buf[base] * 128;
            s->skip_packets = buf[base + 3] + 1;
        }
        s->skip_packets--;
    }
    free(indices);
}
