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
    int key = hdrs[i].subrec_type << 8 | hdrs[i].rec_type;
    if (key == 1760) {
        num_6e0++;
    } else if (key == 3040) {
        num_be0++;
    } else if (key == 960) {
        num_3c0++;
    } else if (key == 2496) {
        num_9c0++;
    }
}
}
