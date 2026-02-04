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

typedef struct MLPParseContext {
    ParseContext pc;
    int bytes_left;
    int in_sync;
    int num_substreams;
} MLPParseContext;

extern  uint8_t *buf;
extern int buf_size;
extern MLPParseContext *mp;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < buf_size - 7; i += step) {
        mp->pc.state = (mp->pc.state << 8) | buf[i];
        if ((mp->pc.state & 4294967294U) == 4168249274U && mp->pc.index + i >= 7) {
            mp->in_sync = 1;
            mp->bytes_left = 0;
            break;
        }
        if (i + 1 < buf_size) {
            mp->pc.state = (mp->pc.state << 8) | buf[i + 1];
            if ((mp->pc.state & 4294967294U) == 4168249274U && mp->pc.index + i + 1 >= 7) {
                mp->in_sync = 1;
                mp->bytes_left = 0;
                break;
            }
        }
    }
    for (; i < buf_size; i++) {
        mp->pc.state = (mp->pc.state << 8) | buf[i];
        if ((mp->pc.state & 4294967294U) == 4168249274U && mp->pc.index + i >= 7) {
            mp->in_sync = 1;
            mp->bytes_left = 0;
            break;
        }
    }
}
