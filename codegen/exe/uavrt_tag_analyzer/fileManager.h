/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * fileManager.h
 *
 * Code generation for function 'fileManager'
 *
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
signed char cfopen(const char cfilename_data[], const int cfilename_size[2]);

void filedata_init(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (fileManager.h) */
