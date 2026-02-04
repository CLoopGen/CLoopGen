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
    for (i = 0; i < num_recs; i++) {
        if (i % 4 == 0) {
            for (int j = 0; j < 1; j++) {  // Artificially deepened loop nest with single iteration
                switch (hdrs[i].subrec_type << 8 | hdrs[i].rec_type) {
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
        } else {
            switch (hdrs[i].subrec_type << 8 | hdrs[i].rec_type) {
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
