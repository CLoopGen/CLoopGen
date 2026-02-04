#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct PixelModel3 {
    uint8_t type;
    uint8_t length;
    uint8_t maxpos;
    uint8_t fshift;
    uint16_t size;
    uint32_t cntsum;
    uint8_t symbols[256];
    uint16_t freqs[256];
    uint16_t freqs1[256];
    uint16_t cnts[256];
    uint8_t dectab[32];
} PixelModel3;

extern PixelModel3 *m;
extern int length;
extern int i;
extern int _usr_index;
extern uint16_t *freqs;
extern uint16_t *freqs1;
extern uint16_t *cnts;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
    // Variant 1: Increased computational intensity by unrolling the loop and reducing conditionals
    int i;
    int limit = length - (length % 4);  // Make it divisible by 4 for safe unrolling
    uint16_t *freqs_local = freqs;
    uint16_t *freqs1_local = freqs1;
    uint16_t *cnts_local = cnts;
    PixelModel3 *m_local = m;

    for (i = 0; i < limit; i += 4) {
        int idx0 = m_local->symbols[i + 0] << 1;
        int idx1 = m_local->symbols[i + 1] << 1;
        int idx2 = m_local->symbols[i + 2] << 1;
        int idx3 = m_local->symbols[i + 3] << 1;

        if (m_local->cnts[i + 0]) {
            freqs_local[m_local->symbols[i + 0]] = m_local->freqs[idx0];
            freqs1_local[m_local->symbols[i + 0]] = m_local->freqs[idx0 + 1];
            cnts_local[m_local->symbols[i + 0]] = m_local->cnts[i + 0];
        }
        if (m_local->cnts[i + 1]) {
            freqs_local[m_local->symbols[i + 1]] = m_local->freqs[idx1];
            freqs1_local[m_local->symbols[i + 1]] = m_local->freqs[idx1 + 1];
            cnts_local[m_local->symbols[i + 1]] = m_local->cnts[i + 1];
        }
        if (m_local->cnts[i + 2]) {
            freqs_local[m_local->symbols[i + 2]] = m_local->freqs[idx2];
            freqs1_local[m_local->symbols[i + 2]] = m_local->freqs[idx2 + 1];
            cnts_local[m_local->symbols[i + 2]] = m_local->cnts[i + 2];
        }
        if (m_local->cnts[i + 3]) {
            freqs_local[m_local->symbols[i + 3]] = m_local->freqs[idx3];
            freqs1_local[m_local->symbols[i + 3]] = m_local->freqs[idx3 + 1];
            cnts_local[m_local->symbols[i + 3]] = m_local->cnts[i + 3];
        }
    }

    // Handle remaining elements
    for (; i < length; i++) {
        if (!m->cnts[i])
            continue;
        index = m->symbols[i];
        freqs[index] = m->freqs[2 * i];
        freqs1[index] = m->freqs[2 * i + 1];
        cnts[index] = m->cnts[i];
    }
}
