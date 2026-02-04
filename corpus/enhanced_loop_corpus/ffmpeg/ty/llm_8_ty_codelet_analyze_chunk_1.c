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
    int limit = num_recs;
    for (i = 0; i < limit; i += 2) {
        uint16_t key1 = (uint16_t)(hdrs[i].subrec_type << 8 | hdrs[i].rec_type);
        switch (key1) {
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
        if (i + 1 < num_recs) {
            uint16_t key2 = (uint16_t)(hdrs[i+1].subrec_type << 8 | hdrs[i+1].rec_type);
            switch (key2) {
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
        }
    }
}
