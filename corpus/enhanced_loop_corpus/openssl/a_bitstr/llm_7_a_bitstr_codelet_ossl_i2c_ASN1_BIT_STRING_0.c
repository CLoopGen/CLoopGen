#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_BIT_STRING;

extern ASN1_BIT_STRING *a;
extern int len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char last_value = 0;
    for (int i = 0; i < len; i++) {
        int idx = len - i - 1;
        unsigned char val = a->data[idx];
        if (val) {
            last_value = val;
        }
        a->flags |= (val & last_value); // Introduce WAW and RAW dependency on a->flags
    }
    if (a->flags) {
        a->length = len; // Loop-carried dependency via a->flags influences a->length
    }
}
