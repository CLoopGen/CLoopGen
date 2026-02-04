#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max_frames;
extern int first_frames;
extern int fsize;
extern int frames;
extern  uint8_t *buf0;
extern  uint8_t *buf2;
extern  uint8_t *buf;
extern  uint8_t *end;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect Memory Access via Index Array (Simulated Frame Table)
    // Precompute valid frame start positions into an auxiliary index array (within buffer space),
    // then iterate over those indices instead of scanning linearly.
    // Simulates indirect access pattern common in sparse data structures.

    uint8_t* temp_index[1024];  // Simulated precomputed frame start pointers (limited size)
    int index_count = 0;
    uint8_t* probe = buf0;

    // Build indirect index table: collect all potential frame starts
    while (probe + 2 < end && index_count < 1024) {
        uint32_t header = ((((const uint8_t*)(probe))[0] << 16) |
                           (((const uint8_t*)(probe))[1] << 8) |
                           ((const uint8_t*)(probe))[2]);
        if ((header >> 13) == 695) {
            temp_index[index_count++] = probe;
        }
        probe++;
    }

    // Now use the indirect table to drive outer loop
    for (int i = 0; i < index_count; i++) {
        buf = temp_index[i];
        buf2 = buf;

        for (frames = 0; buf2 < end; frames++) {
            uint32_t header = ((((const uint8_t*)(buf2))[0] << 16) |
                               (((const uint8_t*)(buf2))[1] << 8) |
                               ((const uint8_t*)(buf2))[2]);

            if ((header >> 13) != 695)
                break;

            fsize = (header & 8191) + 3;
            if (fsize < 7)
                break;

            fsize = ((fsize) > (end - buf2) ? (end - buf2) : (fsize));
            buf2 += fsize;
        }

        max_frames = ((max_frames) > (frames) ? (max_frames) : (frames));
        if (buf == buf0)
            first_frames = frames;
    }

    // Final pass: ensure buf advances beyond last processed region
    if (index_count > 0)
        buf = temp_index[index_count - 1] + 1;
}
