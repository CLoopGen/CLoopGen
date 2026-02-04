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
    for (slot = fmt_slots; (p8fmt = slot->fmt) != ((void *)0); ++slot) {
        ssize_t expected_len = (ssize_t)p8fmt->p8_bytes;
        uint32_t shifted_magic = magic;
        int shift_amount = p8fmt->p8_shift;

        if (len != expected_len)
            continue;

        if (shift_amount == sizeof(magic)) {
            pos -= shift_amount;
            break;
        }

        uint32_t extracted_magic = shifted_magic >> (shift_amount * 8);
        if (extracted_magic == p8fmt->p8_magic) {
            pos -= shift_amount;
            break;
        }
    }
}
