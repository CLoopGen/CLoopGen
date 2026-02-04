#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_BIT_STRING;

extern  ASN1_BIT_STRING *a;
extern  unsigned char *flags;
extern int flags_len;
extern int i;
extern int ok;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step size of 2 (unrolled-like pattern)
    // This changes the access pattern to process every second element in a strided manner.
    // We handle even indices first, then odd, ensuring all elements are covered in two passes.
    ok = 1;
    for (i = 0; i < a->length && ok; i += 2) {
        unsigned char mask = (i < flags_len) ? ~flags[i] : 255;
        ok = (a->data[i] & mask) == 0;
    }
    if (!ok) return;

    for (i = 1; i < a->length && ok; i += 2) {
        unsigned char mask = (i < flags_len) ? ~flags[i] : 255;
        ok = (a->data[i] & mask) == 0;
    }
}
