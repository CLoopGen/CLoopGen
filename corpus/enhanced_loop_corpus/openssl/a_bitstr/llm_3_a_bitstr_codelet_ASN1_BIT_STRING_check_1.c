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
    // Variant 2: Indirect memory access via index mapping using a precomputed index array
    // Simulate indirect access by creating a lookup order (reversed access pattern).
    // Since we cannot modify global declarations, we simulate reverse traversal using arithmetic.
    ok = 1;
    int n = a->length;
    for (i = 0; i < n && ok; ++i) {
        int idx = n - 1 - i;  // Reverse access: process from end to beginning
        unsigned char mask = (idx < flags_len) ? ~flags[idx] : 255;
        ok = (a->data[idx] & mask) == 0;
    }
}
