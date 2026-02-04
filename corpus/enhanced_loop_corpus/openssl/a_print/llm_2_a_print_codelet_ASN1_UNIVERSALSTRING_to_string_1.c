#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_UNIVERSALSTRING;

extern ASN1_UNIVERSALSTRING *s;
extern int i;
extern unsigned char *p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolling to process 4 elements at a time
    int start = (i < 3) ? 3 : i;
    for (int idx = start; idx + 3 < s->length; idx += 4) {
        *(p++) = s->data[idx];
        *(p++) = s->data[idx + 1];
        *(p++) = s->data[idx + 2];
        *(p++) = s->data[idx + 3];
    }
    // Handle remaining elements if any (though original only does every 4th)
    for (; i < s->length; i += 4) {
        *(p++) = s->data[i];
    }
}
