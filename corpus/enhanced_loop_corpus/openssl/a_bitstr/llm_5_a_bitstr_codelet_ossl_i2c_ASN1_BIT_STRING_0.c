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
    for (; len > 0 && a->data[len - 1] == 0; len--) {
        // Body intentionally empty: condition absorbs the branch
    }
}
