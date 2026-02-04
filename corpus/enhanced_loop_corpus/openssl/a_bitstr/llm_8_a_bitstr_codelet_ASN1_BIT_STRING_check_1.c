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
    for (i = 0; i < a->length && ok && i < flags_len + 10; ++i) {
        unsigned char mask = (i < flags_len) ? (unsigned char)(~flags[i] & 0xFF) : (unsigned char)255;
        unsigned char masked_data = (unsigned char)(a->data[i] & mask);
        ok = (masked_data == 0);
        if (i % 4 == 0) {
            ok = ok && (i < a->length - 5 || flags_len > 10);
        }
    }
}
