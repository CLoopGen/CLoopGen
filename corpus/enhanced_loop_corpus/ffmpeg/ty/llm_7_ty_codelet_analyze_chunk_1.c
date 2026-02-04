#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct TyRecHdr {
    int32_t rec_size;
    uint8_t ex[2];
    uint8_t rec_type;
    uint8_t subrec_type;
    uint64_t ty_pts;
} TyRecHdr;

extern int num_recs;
extern int i;
extern TyRecHdr *hdrs;
extern int num_6e0;
extern int num_be0;
extern int num_9c0;
extern int num_3c0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_index = -1;
    for (i = 0; i < num_recs; i++) {
        uint16_t combined_type = (uint16_t)(hdrs[i].subrec_type << 8) | hdrs[i].rec_type;
        if (prev_index != -1) {
            hdrs[i].ty_pts += hdrs[prev_index].ty_pts >> 10;  // Introduce RAW and WAW dependency: current ty_pts depends on previous
        }
        switch (combined_type) {
          case 1760:
            num_6e0++;
            break;
          case 3040:
            num_be0++;
            break;
          case 960:
            num_3c0++;
            break;
          case 2496:
            num_9c0++;
            break;
        }
        prev_index = i;
    }
}
