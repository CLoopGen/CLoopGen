#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct XMAParserContext {
    int skip_packets;
} XMAParserContext;

uint8_t *buf;
XMAParserContext *s;
int duration;
int packet;
int nb_packets;

void init_vars() {
    nb_packets = 131072;  // Approximately 256MB of data accessed (nb_packets * 2048)
    buf = (uint8_t*)calloc(nb_packets, 2048);
    if (!buf) {
        exit(1);
    }

    s = (XMAParserContext*)malloc(sizeof(XMAParserContext));
    if (!s) {
        exit(1);
    }
    s->skip_packets = 0;

    duration = 0;

    // Initialize buf with non-zero values to ensure realistic behavior
    for (int i = 0; i < nb_packets; i++) {
        buf[i * 2048] = 1;         // contributes to duration
        buf[i * 2048 + 3] = 1;     // sets skip_packets to 2 when accessed
    }
}