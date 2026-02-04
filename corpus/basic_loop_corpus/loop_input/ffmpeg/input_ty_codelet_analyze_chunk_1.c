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

int num_recs;
int i;
TyRecHdr *hdrs;
int num_6e0;
int num_be0;
int num_9c0;
int num_3c0;

void init_vars() {
    num_recs = 10000000; // ~10M records, roughly 160MB of data; adjust for ~0.01 sec runtime
    hdrs = (TyRecHdr*)calloc(num_recs, sizeof(TyRecHdr));

    if (!hdrs) {
        exit(1);
    }

    // Initialize a mix of subrec_type and rec_type values to trigger different cases
    for (int j = 0; j < num_recs; j++) {
        // Spread values across the used cases: 1760 (0x6E0), 3040 (0xBE0), 960 (0x3C0), 2496 (0x9C0)
        int code = rand() % 4;
        switch (code) {
            case 0:
                hdrs[j].subrec_type = 0x06;
                hdrs[j].rec_type = 0xe0;
                break;
            case 1:
                hdrs[j].subrec_type = 0x0b;
                hdrs[j].rec_type = 0xe0;
                break;
            case 2:
                hdrs[j].subrec_type = 0x03;
                hdrs[j].rec_type = 0xc0;
                break;
            case 3:
                hdrs[j].subrec_type = 0x09;
                hdrs[j].rec_type = 0xc0;
                break;
        }
        hdrs[j].rec_size = rand();
        hdrs[j].ex[0] = rand();
        hdrs[j].ex[1] = rand();
        hdrs[j].ty_pts = rand();
    }

    num_6e0 = 0;
    num_be0 = 0;
    num_9c0 = 0;
    num_3c0 = 0;
    i = 0;
}