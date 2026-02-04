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
    // Variant 2: Eliminate independent assignments by reordering and introducing artificial WAR dependency
    // We first assign all pref values, then fmt, creating Write-After-Read hazard if reordered by compiler
    // This increases data dependency complexity without changing semantics significantly
    for (i = 0; i < 6; ++i) {
        ret[i].pref = 0;
    }
    for (i = 0; i < 6; ++i) {
        ret[i].fmt = &p8fmt[i];  // WAR: ret[i].fmt written after ret[i].pref was read (in logical flow)
    }
}
