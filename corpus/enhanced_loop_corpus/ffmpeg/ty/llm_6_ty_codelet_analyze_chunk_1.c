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
    int local_6e0 = 0;
    int local_be0 = 0;
    int local_9c0 = 0;
    int local_3c0 = 0;
    for (i = 0; i < num_recs; i++) {
        uint16_t key = (uint16_t)(hdrs[i].subrec_type << 8) | hdrs[i].rec_type;
        switch (key) {
          case 1760:
            local_6e0++;
            break;
          case 3040:
            local_be0++;
            break;
          case 960:
            local_3c0++;
            break;
          case 2496:
            local_9c0++;
            break;
        }
    }
    num_6e0 += local_6e0;
    num_be0 += local_be0;
    num_9c0 += local_9c0;
    num_3c0 += local_3c0;
}
