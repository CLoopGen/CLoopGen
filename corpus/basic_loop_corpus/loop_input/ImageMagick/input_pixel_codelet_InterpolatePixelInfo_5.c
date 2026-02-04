#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    UndefinedClass,
    DirectClass,
    PseudoClass
} ClassType;

typedef enum {
    UndefinedColorspace,
    CMYColorspace,
    CMYKColorspace,
    GRAYColorspace,
    HCLColorspace,
    HCLpColorspace,
    HSBColorspace,
    HSIColorspace,
    HSLColorspace,
    HSVColorspace,
    HWBColorspace,
    LabColorspace,
    LCHColorspace,
    LCHabColorspace,
    LCHuvColorspace,
    LogColorspace,
    LMSColorspace,
    LuvColorspace,
    OHTAColorspace,
    Rec601YCbCrColorspace,
    Rec709YCbCrColorspace,
    RGBColorspace,
    scRGBColorspace,
    sRGBColorspace,
    TransparentColorspace,
    xyYColorspace,
    XYZColorspace,
    YCbCrColorspace,
    YCCColorspace,
    YDbDrColorspace,
    YIQColorspace,
    YPbPrColorspace,
    YUVColorspace,
    LinearGRAYColorspace,
    JzazbzColorspace,
    DisplayP3Colorspace,
    Adobe98Colorspace,
    ProPhotoColorspace,
    OklabColorspace,
    OklchColorspace,
    CAT02LMSColorspace
} ColorspaceType;

typedef enum {
    UndefinedPixelTrait = 0,
    CopyPixelTrait = 1,
    UpdatePixelTrait = 2,
    BlendPixelTrait = 4
} PixelTrait;

typedef unsigned long long MagickSizeType;

typedef double MagickDoubleType;

typedef MagickDoubleType MagickRealType;

typedef struct _PixelInfo {
    ClassType storage_class;
    ColorspaceType colorspace;
    PixelTrait alpha_trait;
    double fuzz;
    size_t depth;
    MagickSizeType count;
    MagickRealType red;
    MagickRealType green;
    MagickRealType blue;
    MagickRealType black;
    MagickRealType alpha;
    MagickRealType index;
} PixelInfo;

double y;
double alpha[16];
double gamma;
PixelInfo pixels[16];
ssize_t i;
ssize_t y_offset;

void init_vars() {
    y = 1.0;
    y_offset = 0;
    gamma = 1.0;
    for (int j = 0; j < 16; j++) {
        alpha[j] = (double)(j + 1) * 0.1;
        pixels[j].storage_class = (j % 2) ? DirectClass : UndefinedClass;
        pixels[j].colorspace = RGBColorspace;
        pixels[j].alpha_trait = (j < 8) ? UpdatePixelTrait : BlendPixelTrait;
        pixels[j].fuzz = 0.0;
        pixels[j].depth = 8;
        pixels[j].count = 1ULL << j;
        pixels[j].red = ((double)(j + 1) * 0.05);
        pixels[j].green = ((double)(j + 2) * 0.06);
        pixels[j].blue = ((double)(j + 3) * 0.07);
        pixels[j].black = ((double)(j % 4) * 0.1);
        pixels[j].alpha = ((double)(j % 5) * 0.2);
        pixels[j].index = 0.0;
    }
}