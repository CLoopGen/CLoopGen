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



void loop(){
    uint8_t *local_buf = buf;
    int local_max_frames = max_frames;
    int local_first_frames = first_frames;

    for (; local_buf < end; ) {
        uint8_t *local_buf2 = local_buf;
        int local_frames = 0;

        for (uint8_t *scan = local_buf; scan < end; ) {
            if (scan + 3 > end) break;

            uint32_t header = (((const uint8_t *)scan)[0] << 16) |
                              (((const uint8_t *)scan)[1] << 8) |
                               ((const uint8_t *)scan)[2];

            if ((header >> 13) != 695) break;

            int local_fsize = (header & 8191) + 3;
            if (local_fsize < 7) break;
            local_fsize = (local_fsize > (end - scan)) ? (end - scan) : local_fsize;

            scan += local_fsize;
            local_frames++;
        }

        local_max_frames = (local_max_frames > local_frames) ? local_max_frames : local_frames;

        if (local_buf == buf0) {
            local_first_frames = local_frames;
        }

        local_buf = local_buf2 + 1;
    }

    max_frames = local_max_frames;
    first_frames = local_first_frames;
    buf = local_buf; // Reflect final state if needed (though original doesn't update global buf meaningfully beyond loop)
}
