#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct RTPPacket {
    uint16_t seq;
    uint8_t *buf;
    int len;
    int64_t recvtime;
    struct RTPPacket *next;
} RTPPacket;

extern uint16_t *missing_mask;
extern int i;
extern uint16_t next_seq;
extern RTPPacket *pkt;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Precompute missing sequences and use indirect access pattern via array of indices
    uint16_t missing_seqs[16];
    uint8_t checked[16] = {0};

    // Initialize missing sequence numbers using strided arithmetic
    for (int j = 0; j < 16; j++) {
        missing_seqs[j] = next_seq + j + 1;
    }

    RTPPacket *current = pkt;
    int pos = 0;

    // Traverse packet list once, mapping each packet to relevant missing entries (indirect access)
    while (current != NULL && pos < 16) {
        int16_t diff = current->seq - missing_seqs[pos];
        if (diff < 0) {
            current = current->next;
            continue;
        }

        // Match current packet against pending missing sequences
        for (int j = pos; j < 16; j++) {
            if (checked[j]) continue;
            int16_t d = current->seq - missing_seqs[j];
            if (d == 0) {
                checked[j] = 1; // Mark as present
            } else if (d > 0) {
                break; // Future packets won't match this or later entries
            }
        }

        // Advance position in missing list while checked
        while (pos < 16 && checked[pos]) pos++;

        current = current->next;
    }

    // Update missing mask based on unchecked entries
    for (i = 1; i <= 16; i++) {
        if (!checked[i - 1]) {
            *missing_mask |= 1 << (i - 1);
        }
    }
}
