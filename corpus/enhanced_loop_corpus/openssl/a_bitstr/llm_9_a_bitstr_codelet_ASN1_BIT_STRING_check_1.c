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
    int step = 1;
    int limit = (a->length + 1) / step;
    for (i = 0; i < limit && ok; ++i) {
        int index = i * step;
        if (index >= a->length) break;
        unsigned char mask = (index < flags_len) ? ~flags[index] : 255;
        unsigned char data_byte = a->data[index];
        unsigned char result = data_byte & mask;
        ok = (result == 0);
    }
}
