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

extern ML_COMMON_PKCS8_FMT_PREF *fmt_slots;
extern ML_COMMON_PKCS8_FMT_PREF *slot;
extern  ML_COMMON_PKCS8_FMT *p8fmt;
extern  uint8_t *pos;
extern int len;
extern uint32_t magic;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access via Array Indexing
    // Instead of pointer increment, use index-based access for predictable stride
    ML_COMMON_PKCS8_FMT_PREF *slots = fmt_slots;
    size_t i = 0;
    for (; (p8fmt = slots[i].fmt) != ((void *)0); ++i) {
        if (len != (ssize_t)p8fmt->p8_bytes)
            continue;
        if (p8fmt->p8_shift == sizeof(magic) || (magic >> (p8fmt->p8_shift * 8)) == p8fmt->p8_magic) {
            pos -= p8fmt->p8_shift;
            slot = &slots[i]; // Update slot to point to matched entry
            break;
        }
    }
}
