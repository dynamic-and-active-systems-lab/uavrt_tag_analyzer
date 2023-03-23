/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * uavrt_tag_analyzer_types.h
 *
 * Code generation for function 'uavrt_tag_analyzer'
 *
 */

#ifndef UAVRT_TAG_ANALYZER_TYPES_H
#define UAVRT_TAG_ANALYZER_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_rtBoundsCheckInfo
#define typedef_rtBoundsCheckInfo
typedef struct {
  int iFirst;
  int iLast;
  int lineNo;
  int colNo;
  const char *aName;
  const char *fName;
  const char *pName;
  int checkKind;
} rtBoundsCheckInfo;
#endif /* typedef_rtBoundsCheckInfo */

#ifndef typedef_rtEqualityCheckInfo
#define typedef_rtEqualityCheckInfo
typedef struct {
  int nDims;
  int lineNo;
  int colNo;
  const char *fName;
  const char *pName;
} rtEqualityCheckInfo;
#endif /* typedef_rtEqualityCheckInfo */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  double *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T
typedef struct {
  creal_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
} emxArray_creal_T;
#endif /* typedef_emxArray_creal_T */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T {
  boolean_T *data;
  int *size;
  int allocatedSize;
  int numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_boolean_T */
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /* typedef_emxArray_boolean_T */

#ifndef typedef_rtDoubleCheckInfo
#define typedef_rtDoubleCheckInfo
typedef struct {
  int lineNo;
  const char *fName;
} rtDoubleCheckInfo;
#endif /* typedef_rtDoubleCheckInfo */

#endif
/* End of code generation (uavrt_tag_analyzer_types.h) */
