#include <stdio.h>

#include <inttypes.h>

typedef struct {
    const char *p8_name;
    size_t p8_bytes;
    int p8_shift;
    uint32_t p8_magic;
    uint16_t seed_magic;
    size_t seed_offset;
    size_t seed_length;
    uint32_t priv_magic;
    size_t priv_offset;
    size_t priv_length;
    size_t pub_offset;
    size_t pub_length;
} ML_COMMON_PKCS8_FMT;

typedef struct {
    const ML_COMMON_PKCS8_FMT *fmt;
    int pref;
} ML_COMMON_PKCS8_FMT_PREF;

extern  ML_COMMON_PKCS8_FMT *p8fmt;
extern ML_COMMON_PKCS8_FMT_PREF *ret;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased loop nesting depth (two nested loops, outer controls unrolling factor)
    for (int block = 0; block < 2; ++block) {
        for (int inner = 0; inner < 3; ++inner) {
            int i = block * 3 + inner;
            ret[i].fmt = &p8fmt[i];
            ret[i].pref = 0;
        }
    }
}
