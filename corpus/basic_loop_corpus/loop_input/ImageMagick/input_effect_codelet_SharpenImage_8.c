#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    UndefinedKernel,
    UnityKernel,
    GaussianKernel,
    DoGKernel,
    LoGKernel,
    BlurKernel,
    CometKernel,
    BinomialKernel,
    LaplacianKernel,
    SobelKernel,
    FreiChenKernel,
    RobertsKernel,
    PrewittKernel,
    CompassKernel,
    KirschKernel,
    DiamondKernel,
    SquareKernel,
    RectangleKernel,
    OctagonKernel,
    DiskKernel,
    PlusKernel,
    CrossKernel,
    RingKernel,
    PeaksKernel,
    EdgesKernel,
    CornersKernel,
    DiagonalsKernel,
    LineEndsKernel,
    LineJunctionsKernel,
    RidgesKernel,
    ConvexHullKernel,
    ThinSEKernel,
    SkeletonKernel,
    ChebyshevKernel,
    ManhattanKernel,
    OctagonalKernel,
    EuclideanKernel,
    UserDefinedKernel
} KernelInfoType;

typedef double MagickDoubleType;
typedef MagickDoubleType MagickRealType;

typedef struct _KernelInfo {
    KernelInfoType type;
    size_t width;
    size_t height;
    ssize_t x;
    ssize_t y;
    MagickRealType *values;
    double minimum;
    double maximum;
    double negative_range;
    double positive_range;
    double angle;
    struct _KernelInfo *next;
    size_t signature;
} KernelInfo;

double gamma;
KernelInfo *kernel_info;
ssize_t i;

void init_vars() {
    gamma = 1.5;

    kernel_info = (KernelInfo*)malloc(sizeof(KernelInfo));
    kernel_info->type = UnityKernel;
    kernel_info->width = 8192;
    kernel_info->height = 4096;
    kernel_info->x = 0;
    kernel_info->y = 0;
    kernel_info->values = (MagickRealType*)malloc(kernel_info->width * kernel_info->height * sizeof(MagickRealType));
    for (size_t idx = 0; idx < kernel_info->width * kernel_info->height; idx++) {
        kernel_info->values[idx] = 1.0;
    }
    kernel_info->minimum = 0.0;
    kernel_info->maximum = 1.0;
    kernel_info->negative_range = 0.0;
    kernel_info->positive_range = 1.0;
    kernel_info->angle = 0.0;
    kernel_info->next = NULL;
    kernel_info->signature = 123456789ULL;
}