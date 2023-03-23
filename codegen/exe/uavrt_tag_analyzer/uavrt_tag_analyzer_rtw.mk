###########################################################################
## Makefile generated for component 'uavrt_tag_analyzer'. 
## 
## Makefile     : uavrt_tag_analyzer_rtw.mk
## Generated on : Thu Mar 23 11:44:40 2023
## Final product: $(START_DIR)/uavrt_tag_analyzer
## Product type : executable
## 
###########################################################################

###########################################################################
## MACROS
###########################################################################

# Macro Descriptions:
# PRODUCT_NAME            Name of the system to build
# MAKEFILE                Name of this makefile

PRODUCT_NAME              = uavrt_tag_analyzer
MAKEFILE                  = uavrt_tag_analyzer_rtw.mk
MATLAB_ROOT               = /Applications/MATLAB_R2023a.app
MATLAB_BIN                = /Applications/MATLAB_R2023a.app/bin
MATLAB_ARCH_BIN           = $(MATLAB_BIN)/maci64
START_DIR                 = /Users/mshafer/Library/CloudStorage/OneDrive-NorthernArizonaUniversity/CODE_PLAYGROUND/uavrt_tag_analyzer
TGT_FCN_LIB               = ISO_C
SOLVER_OBJ                = 
CLASSIC_INTERFACE         = 0
MODEL_HAS_DYNAMICALLY_LOADED_SFCNS = 
RELATIVE_PATH_TO_ANCHOR   = ../../..
C_STANDARD_OPTS           = -fno-common -fexceptions
CPP_STANDARD_OPTS         = -std=c++14 -fno-common -fexceptions

###########################################################################
## TOOLCHAIN SPECIFICATIONS
###########################################################################

# Toolchain Name:          Xcode with Clang | gmake (64-bit Mac)
# Supported Version(s):    
# ToolchainInfo Version:   2023a
# Specification Revision:  1.0
# 
#-------------------------------------------
# Macros assumed to be defined elsewhere
#-------------------------------------------

# C_STANDARD_OPTS
# CPP_STANDARD_OPTS

#-----------
# MACROS
#-----------

ARCHS             = x86_64
XCODE_SDK_VER     = $(shell perl $(MATLAB_ROOT)/rtw/c/tools/macsdkver.pl)
XCODE_SDK         = MacOSX$(XCODE_SDK_VER).sdk
XCODE_DEVEL_DIR   = $(shell xcode-select -print-path)
XCODE_SDK_ROOT    = $(XCODE_DEVEL_DIR)/Platforms/MacOSX.platform/Developer/SDKs/$(XCODE_SDK)

TOOLCHAIN_SRCS = 
TOOLCHAIN_INCS = 
TOOLCHAIN_LIBS = 

#------------------------
# BUILD TOOL COMMANDS
#------------------------

# C Compiler: Clang C Compiler
CC = xcrun clang

# Linker: Clang Linker
LD = xcrun clang++

# C++ Compiler: Clang C++ Compiler
CPP = xcrun clang++

# C++ Linker: Clang C++ Linker
CPP_LD = xcrun clang++

# Archiver: Clang Archiver
AR = xcrun ar

# MEX Tool: MEX Tool
MEX_PATH = $(MATLAB_ARCH_BIN)
MEX = "$(MEX_PATH)/mex"

# Download: Download
DOWNLOAD =

# Execute: Execute
EXECUTE = $(PRODUCT)

# Builder: GMAKE Utility
MAKE_PATH = %MATLAB%/bin/maci64
MAKE = "$(MAKE_PATH)/gmake"


#-------------------------
# Directives/Utilities
#-------------------------

CDEBUG              = -g
C_OUTPUT_FLAG       = -o
LDDEBUG             = -g
OUTPUT_FLAG         = -o
CPPDEBUG            = -g
CPP_OUTPUT_FLAG     = -o
CPPLDDEBUG          = -g
OUTPUT_FLAG         = -o
ARDEBUG             =
STATICLIB_OUTPUT_FLAG =
MEX_DEBUG           = -g
RM                  = @rm -f
ECHO                = @echo
MV                  = @mv
RUN                 =

#--------------------------------------
# "Faster Runs" Build Configuration
#--------------------------------------

ARFLAGS              = ruvs
CFLAGS               = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(C_STANDARD_OPTS) -mmacosx-version-min=10.15 \
                       -O3
CPPFLAGS             = -c -isysroot $(XCODE_SDK_ROOT) -arch $(ARCHS) $(CPP_STANDARD_OPTS) -mmacosx-version-min=10.15 \
                       -O3
CPP_LDFLAGS          = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR)
CPP_SHAREDLIB_LDFLAGS  = -arch $(ARCHS)  \
                         -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) \
                         -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)
DOWNLOAD_FLAGS       =
EXECUTE_FLAGS        =
LDFLAGS              = -arch $(ARCHS) -isysroot $(XCODE_SDK_ROOT) -Wl,-rpath,@executable_path -Wl,-rpath,@executable_path/$(RELATIVE_PATH_TO_ANCHOR)
MEX_CPPFLAGS         =
MEX_CPPLDFLAGS       =
MEX_CFLAGS           =
MEX_LDFLAGS          =
MAKE_FLAGS           = -f $(MAKEFILE)
SHAREDLIB_LDFLAGS    = -arch $(ARCHS)  \
                       -dynamiclib -install_name @rpath/$(notdir $(PRODUCT)) -isysroot $(XCODE_SDK_ROOT) \
                       -Wl,$(LD_NAMESPACE) $(LD_UNDEFS)



###########################################################################
## OUTPUT INFO
###########################################################################

PRODUCT = $(START_DIR)/uavrt_tag_analyzer
PRODUCT_TYPE = "executable"
BUILD_TYPE = "Executable"

###########################################################################
## INCLUDE PATHS
###########################################################################

INCLUDES_BUILDINFO = -I$(START_DIR)/codegen/exe/uavrt_tag_analyzer -I$(START_DIR) -I$(START_DIR)/custom_mains -I$(MATLAB_ROOT)/extern/include

INCLUDES = $(INCLUDES_BUILDINFO)

###########################################################################
## DEFINES
###########################################################################

DEFINES_CUSTOM = 
DEFINES_STANDARD = -DMODEL=uavrt_tag_analyzer

DEFINES = $(DEFINES_CUSTOM) $(DEFINES_STANDARD)

###########################################################################
## SOURCE FILES
###########################################################################

SRCS = $(START_DIR)/custom_mains/main.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/uavrt_tag_analyzer_data.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/rt_nonfinite.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/rtGetNaN.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/rtGetInf.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/uavrt_tag_analyzer_initialize.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/uavrt_tag_analyzer_terminate.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/uavrt_tag_analyzer.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/fileManager.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/fread.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/ifWhileCond.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/indexShapeCheck.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/factor.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/eml_primes_core.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/decimate.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/firls.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/xnrm2.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/grpdelay.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/fft.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/FFTImplementationCallback.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/islinphase.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/minOrMax.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/find.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/abs.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/histcounts.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/diff.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/mean.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/std.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/locateoutliers.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/median.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/quickselect.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/combineVectorElements.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/colon.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/strcmp.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/eml_int_forloop_overflow_check.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/nullAssignment.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/xgeqp3.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/fftshift.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/eml_mtimes_helper.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/div.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/levdown.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/uavrt_tag_analyzer_emxutil.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/mldivide.c $(START_DIR)/codegen/exe/uavrt_tag_analyzer/uavrt_tag_analyzer_rtwutil.c

ALL_SRCS = $(SRCS)

###########################################################################
## OBJECTS
###########################################################################

OBJS = main.o uavrt_tag_analyzer_data.o rt_nonfinite.o rtGetNaN.o rtGetInf.o uavrt_tag_analyzer_initialize.o uavrt_tag_analyzer_terminate.o uavrt_tag_analyzer.o fileManager.o fread.o ifWhileCond.o indexShapeCheck.o factor.o eml_primes_core.o decimate.o firls.o xnrm2.o grpdelay.o fft.o FFTImplementationCallback.o islinphase.o minOrMax.o find.o abs.o histcounts.o diff.o mean.o std.o locateoutliers.o median.o quickselect.o combineVectorElements.o colon.o strcmp.o eml_int_forloop_overflow_check.o nullAssignment.o xgeqp3.o fftshift.o eml_mtimes_helper.o div.o levdown.o uavrt_tag_analyzer_emxutil.o mldivide.o uavrt_tag_analyzer_rtwutil.o

ALL_OBJS = $(OBJS)

###########################################################################
## PREBUILT OBJECT FILES
###########################################################################

PREBUILT_OBJS = 

###########################################################################
## LIBRARIES
###########################################################################

LIBS = 

###########################################################################
## SYSTEM LIBRARIES
###########################################################################

SYSTEM_LIBS =  -lm

###########################################################################
## ADDITIONAL TOOLCHAIN FLAGS
###########################################################################

#---------------
# C Compiler
#---------------

CFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CFLAGS += $(CFLAGS_BASIC)

#-----------------
# C++ Compiler
#-----------------

CPPFLAGS_BASIC = $(DEFINES) $(INCLUDES)

CPPFLAGS += $(CPPFLAGS_BASIC)

###########################################################################
## INLINED COMMANDS
###########################################################################

###########################################################################
## PHONY TARGETS
###########################################################################

.PHONY : all build buildobj clean info prebuild download execute


all : build
	@echo "### Successfully generated all binary outputs."


build : prebuild $(PRODUCT)


buildobj : prebuild $(OBJS) $(PREBUILT_OBJS)
	@echo "### Successfully generated all binary outputs."


prebuild : 


download : $(PRODUCT)


execute : download
	@echo "### Invoking postbuild tool "Execute" ..."
	$(EXECUTE) $(EXECUTE_FLAGS)
	@echo "### Done invoking postbuild tool."


###########################################################################
## FINAL TARGET
###########################################################################

#-------------------------------------------
# Create a standalone executable            
#-------------------------------------------

$(PRODUCT) : $(OBJS) $(PREBUILT_OBJS)
	@echo "### Creating standalone executable "$(PRODUCT)" ..."
	$(LD) $(LDFLAGS) -o $(PRODUCT) $(OBJS) $(SYSTEM_LIBS) $(TOOLCHAIN_LIBS)
	@echo "### Created: $(PRODUCT)"


###########################################################################
## INTERMEDIATE TARGETS
###########################################################################

#---------------------
# SOURCE-TO-OBJECT
#---------------------

%.o : %.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : %.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/custom_mains/%.c
	$(CC) $(CFLAGS) -o "$@" "$<"


%.o : $(START_DIR)/custom_mains/%.cpp
	$(CPP) $(CPPFLAGS) -o "$@" "$<"


main.o : $(START_DIR)/custom_mains/main.c
	$(CC) $(CFLAGS) -o "$@" "$<"


uavrt_tag_analyzer_data.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/uavrt_tag_analyzer_data.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rt_nonfinite.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/rt_nonfinite.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetNaN.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/rtGetNaN.c
	$(CC) $(CFLAGS) -o "$@" "$<"


rtGetInf.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/rtGetInf.c
	$(CC) $(CFLAGS) -o "$@" "$<"


uavrt_tag_analyzer_initialize.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/uavrt_tag_analyzer_initialize.c
	$(CC) $(CFLAGS) -o "$@" "$<"


uavrt_tag_analyzer_terminate.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/uavrt_tag_analyzer_terminate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


uavrt_tag_analyzer.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/uavrt_tag_analyzer.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fileManager.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/fileManager.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fread.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/fread.c
	$(CC) $(CFLAGS) -o "$@" "$<"


ifWhileCond.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/ifWhileCond.c
	$(CC) $(CFLAGS) -o "$@" "$<"


indexShapeCheck.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/indexShapeCheck.c
	$(CC) $(CFLAGS) -o "$@" "$<"


factor.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/factor.c
	$(CC) $(CFLAGS) -o "$@" "$<"


eml_primes_core.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/eml_primes_core.c
	$(CC) $(CFLAGS) -o "$@" "$<"


decimate.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/decimate.c
	$(CC) $(CFLAGS) -o "$@" "$<"


firls.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/firls.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xnrm2.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/xnrm2.c
	$(CC) $(CFLAGS) -o "$@" "$<"


grpdelay.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/grpdelay.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fft.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/fft.c
	$(CC) $(CFLAGS) -o "$@" "$<"


FFTImplementationCallback.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/FFTImplementationCallback.c
	$(CC) $(CFLAGS) -o "$@" "$<"


islinphase.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/islinphase.c
	$(CC) $(CFLAGS) -o "$@" "$<"


minOrMax.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/minOrMax.c
	$(CC) $(CFLAGS) -o "$@" "$<"


find.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/find.c
	$(CC) $(CFLAGS) -o "$@" "$<"


abs.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/abs.c
	$(CC) $(CFLAGS) -o "$@" "$<"


histcounts.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/histcounts.c
	$(CC) $(CFLAGS) -o "$@" "$<"


diff.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/diff.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mean.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/mean.c
	$(CC) $(CFLAGS) -o "$@" "$<"


std.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/std.c
	$(CC) $(CFLAGS) -o "$@" "$<"


locateoutliers.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/locateoutliers.c
	$(CC) $(CFLAGS) -o "$@" "$<"


median.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/median.c
	$(CC) $(CFLAGS) -o "$@" "$<"


quickselect.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/quickselect.c
	$(CC) $(CFLAGS) -o "$@" "$<"


combineVectorElements.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/combineVectorElements.c
	$(CC) $(CFLAGS) -o "$@" "$<"


colon.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/colon.c
	$(CC) $(CFLAGS) -o "$@" "$<"


strcmp.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/strcmp.c
	$(CC) $(CFLAGS) -o "$@" "$<"


eml_int_forloop_overflow_check.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/eml_int_forloop_overflow_check.c
	$(CC) $(CFLAGS) -o "$@" "$<"


nullAssignment.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/nullAssignment.c
	$(CC) $(CFLAGS) -o "$@" "$<"


xgeqp3.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/xgeqp3.c
	$(CC) $(CFLAGS) -o "$@" "$<"


fftshift.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/fftshift.c
	$(CC) $(CFLAGS) -o "$@" "$<"


eml_mtimes_helper.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/eml_mtimes_helper.c
	$(CC) $(CFLAGS) -o "$@" "$<"


div.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/div.c
	$(CC) $(CFLAGS) -o "$@" "$<"


levdown.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/levdown.c
	$(CC) $(CFLAGS) -o "$@" "$<"


uavrt_tag_analyzer_emxutil.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/uavrt_tag_analyzer_emxutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


mldivide.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/mldivide.c
	$(CC) $(CFLAGS) -o "$@" "$<"


uavrt_tag_analyzer_rtwutil.o : $(START_DIR)/codegen/exe/uavrt_tag_analyzer/uavrt_tag_analyzer_rtwutil.c
	$(CC) $(CFLAGS) -o "$@" "$<"


###########################################################################
## DEPENDENCIES
###########################################################################

$(ALL_OBJS) : rtw_proj.tmw $(MAKEFILE)


###########################################################################
## MISCELLANEOUS TARGETS
###########################################################################

info : 
	@echo "### PRODUCT = $(PRODUCT)"
	@echo "### PRODUCT_TYPE = $(PRODUCT_TYPE)"
	@echo "### BUILD_TYPE = $(BUILD_TYPE)"
	@echo "### INCLUDES = $(INCLUDES)"
	@echo "### DEFINES = $(DEFINES)"
	@echo "### ALL_SRCS = $(ALL_SRCS)"
	@echo "### ALL_OBJS = $(ALL_OBJS)"
	@echo "### LIBS = $(LIBS)"
	@echo "### MODELREF_LIBS = $(MODELREF_LIBS)"
	@echo "### SYSTEM_LIBS = $(SYSTEM_LIBS)"
	@echo "### TOOLCHAIN_LIBS = $(TOOLCHAIN_LIBS)"
	@echo "### CFLAGS = $(CFLAGS)"
	@echo "### LDFLAGS = $(LDFLAGS)"
	@echo "### SHAREDLIB_LDFLAGS = $(SHAREDLIB_LDFLAGS)"
	@echo "### CPPFLAGS = $(CPPFLAGS)"
	@echo "### CPP_LDFLAGS = $(CPP_LDFLAGS)"
	@echo "### CPP_SHAREDLIB_LDFLAGS = $(CPP_SHAREDLIB_LDFLAGS)"
	@echo "### ARFLAGS = $(ARFLAGS)"
	@echo "### MEX_CFLAGS = $(MEX_CFLAGS)"
	@echo "### MEX_CPPFLAGS = $(MEX_CPPFLAGS)"
	@echo "### MEX_LDFLAGS = $(MEX_LDFLAGS)"
	@echo "### MEX_CPPLDFLAGS = $(MEX_CPPLDFLAGS)"
	@echo "### DOWNLOAD_FLAGS = $(DOWNLOAD_FLAGS)"
	@echo "### EXECUTE_FLAGS = $(EXECUTE_FLAGS)"
	@echo "### MAKE_FLAGS = $(MAKE_FLAGS)"


clean : 
	$(ECHO) "### Deleting all derived files ..."
	$(RM) $(PRODUCT)
	$(RM) $(ALL_OBJS)
	$(ECHO) "### Deleted all derived files."


