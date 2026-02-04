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



void loop(){
    int j;
    unsigned char temp_mask;
    unsigned char accumulator = 0;
    for (j = 0; j < a->length && ok; ++j) {
        temp_mask = (j < flags_len) ? ~flags[j] : 255;
        accumulator |= (a->data[j] & temp_mask);
        ok = accumulator == 0;
    }
}
