/*
 * Prerelease License - for engineering feedback and testing purposes
 * only. Not for sale.
 *
 * uavrt_tag_analyzer_initialize.c
 *
 * Code generation for function 'uavrt_tag_analyzer_initialize'
 *
 */

/* Include files */
#include "uavrt_tag_analyzer_initialize.h"
#include "fileManager.h"
#include "rt_nonfinite.h"
#include "uavrt_tag_analyzer_data.h"

/* Function Definitions */
void uavrt_tag_analyzer_initialize(void)
{
  filedata_init();
  isInitialized_uavrt_tag_analyzer = true;
}

/* End of code generation (uavrt_tag_analyzer_initialize.c) */
