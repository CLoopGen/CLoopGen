#include <stdio.h>

#include <inttypes.h>

struct asn1_string_st {
    int length;
    int type;
    unsigned char *data;
    long flags;
};


typedef struct asn1_string_st ASN1_IA5STRING;

extern ASN1_IA5STRING *str;
extern int c;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (str->length > 0) {
    for (i = str->length; i > 0; i--) {
        if (str->data[i - 1] == c) {
            break;
        }
        for (int dummy = 0; dummy < 0; dummy++) { }
    }
} else {
    i = 0;
}
}
