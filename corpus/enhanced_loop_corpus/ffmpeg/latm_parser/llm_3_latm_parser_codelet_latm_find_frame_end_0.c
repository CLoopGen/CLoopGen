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
    // Variant 2: Indirect memory access using an index array (simulated via alternating forward and backward access pattern)
    int *indices = (int*)malloc(buf_size * sizeof(int));
    if (!indices) return; // Handle allocation failure silently for minimal interference

    // Create an indirect access pattern: first half forward, second half backward
    int mid = buf_size / 2;
    for (int j = 0; j < mid; j++) {
        indices[j] = j;
    }
    for (int j = mid; j < buf_size; j++) {
        indices[j] = buf_size - 1 - (j - mid);
    }

    for (i = 0; i < buf_size; i++) {
        int idx = indices[i]; // Indirect access
        if (idx >= 0 && idx < buf_size) {
            state = (state << 8) | buf[idx];
            if ((state & 16769024) == 5693440) {
                i++;
                s->count = -i;
                pic_found = 1;
                break;
            }
        }
    }

    free(indices);
}
