#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ParseContext {
    uint8_t *buffer;
    int index;
    int last_index;
    unsigned int buffer_size;
    uint32_t state;
    int frame_start_found;
    int overread;
    int overread_index;
    uint64_t state64;
} ParseContext;

typedef struct LATMParseContext {
    ParseContext pc;
    int count;
} LATMParseContext;

extern  uint8_t *buf;
extern int buf_size;
extern LATMParseContext *s;
extern int pic_found;
extern int i;
extern uint32_t state;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = buf_size - 7;
    for (i = 0; i < limit; i += 8) {
        state = (state << 8) | buf[i];
        if ((state & 16769024) == 5693440) {
            i++;
            s->count = -i;
            pic_found = 1;
            break;
        }
        state = (state << 8) | buf[i + 1];
        if ((state & 16769024) == 5693440) {
            i += 2;
            s->count = -i;
            pic_found = 1;
            break;
        }
        state = (state << 8) | buf[i + 2];
        if ((state & 16769024) == 5693440) {
            i += 3;
            s->count = -i;
            pic_found = 1;
            break;
        }
        state = (state << 8) | buf[i + 3];
        if ((state & 16769024) == 5693440) {
            i += 4;
            s->count = -i;
            pic_found = 1;
            break;
        }
        state = (state << 8) | buf[i + 4];
        if ((state & 16769024) == 5693440) {
            i += 5;
            s->count = -i;
            pic_found = 1;
            break;
        }
        state = (state << 8) | buf[i + 5];
        if ((state & 16769024) == 5693440) {
            i += 6;
            s->count = -i;
            pic_found = 1;
            break;
        }
        state = (state << 8) | buf[i + 6];
        if ((state & 16769024) == 5693440) {
            i += 7;
            s->count = -i;
            pic_found = 1;
            break;
        }
        state = (state << 8) | buf[i + 7];
        if ((state & 16769024) == 5693440) {
            i += 8;
            s->count = -i;
            pic_found = 1;
            break;
        }
    }
    // Handle remaining elements
    for (; i < buf_size; i++) {
        state = (state << 8) | buf[i];
        if ((state & 16769024) == 5693440) {
            i++;
            s->count = -i;
            pic_found = 1;
            break;
        }
    }
}
