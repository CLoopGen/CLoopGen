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
    int j;
    unsigned char prev = 0;
    for (j = 3; j < s->length; j += 4) {
        unsigned char curr = s->data[j] ^ prev;  // Introduce RAW dependency: current value depends on previous iteration
        prev = s->data[j];                       // WAW: 'prev' write-after-write dependency across iterations
        *(p++) = curr;
    }
}
