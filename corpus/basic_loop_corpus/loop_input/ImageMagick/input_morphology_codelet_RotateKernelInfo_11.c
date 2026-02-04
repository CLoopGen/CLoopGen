#include <stddef.h>
#include <stdlib.h>

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

KernelInfo *kernel;
ssize_t i;
ssize_t j;
ssize_t x;
ssize_t y;
MagickRealType *k;
MagickRealType t;

void init_vars() {
    kernel = (KernelInfo*)malloc(sizeof(KernelInfo));
    kernel->type = UnityKernel;
    kernel->width = 1024;
    kernel->height = 1024;
    kernel->x = 0;
    kernel->y = 0;
    kernel->minimum = 0.0;
    kernel->maximum = 1.0;
    kernel->negative_range = -1.0;
    kernel->positive_range = 1.0;
    kernel->angle = 0.0;
    kernel->next = NULL;
    kernel->signature = 0x12345678UL;

    size_t data_size = kernel->width * kernel->height;
    k = (MagickRealType*)calloc(data_size, sizeof(MagickRealType));

    for (size_t idx = 0; idx < data_size; idx++) {
        k[idx] = (MagickRealType)(idx % 1000) / 1000.0;
    }

    kernel->values = k;
}