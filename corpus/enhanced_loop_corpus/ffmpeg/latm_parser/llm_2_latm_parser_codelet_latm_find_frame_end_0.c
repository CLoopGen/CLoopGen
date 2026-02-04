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
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < buf_size; i += 2) {
        if (i + 1 < buf_size) {
            state = (state << 16) | (buf[i] << 8) | buf[i + 1];
            if ((state & 16769024) == 5693440) {
                i++;
                s->count = -i;
                pic_found = 1;
                break;
            }
        } else {
            state = (state << 8) | buf[i];
            if ((state & 16769024) == 5693440) {
                i++;
                s->count = -i;
                pic_found = 1;
                break;
            }
        }
    }
}
