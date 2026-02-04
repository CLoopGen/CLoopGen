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
    // Variant 1: Introduce loop-carried dependency via pref index based on previous iteration's fmt value
    // This creates a WAW and RAW dependency by using a computed value from prior iteration
    ret[0].fmt = &p8fmt[0];
    ret[0].pref = 0;
    for (i = 1; i < 6; ++i) {
        ret[i].fmt = &p8fmt[i];
        ret[i].pref = ret[i-1].pref + 1;  // Loop-carried RAW and WAW: pref depends on previous pref
    }
}
