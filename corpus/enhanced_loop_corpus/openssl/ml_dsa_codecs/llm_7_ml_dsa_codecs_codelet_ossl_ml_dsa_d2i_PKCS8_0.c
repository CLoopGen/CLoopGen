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
    uint8_t *temp_pos = pos;
    int matched = 0;
    for (slot = fmt_slots; !matched && (p8fmt = slot->fmt) != ((void *)0); ++slot) {
        if (len == (ssize_t)p8fmt->p8_bytes) {
            if (p8fmt->p8_shift < sizeof(magic)/2 || (magic >> (p8fmt->p8_shift * 8)) == p8fmt->p8_magic) {
                temp_pos = pos - p8fmt->p8_shift;
                matched = 1;
            }
        }
    }
    if (matched) {
        pos = temp_pos;
    }
}
