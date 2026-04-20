###########################################################################
# CMakeLists.txt generated for component FFT
# Product type: STATIC library
###########################################################################
cmake_minimum_required(VERSION 3.12)
project(FFT)

# Propagate the CMAKE_EXPORT_COMPILE_COMMANDS variable from the 
# environment if it is defined as an environment variable, but not as a 
# CMake variable. This is to work around a bug in CMake 3.19 when the 
# "NMake Makefiles" generator is selected.
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()

if(NOT DEFINED CMAKE_POSITION_INDEPENDENT_CODE)
    set(CMAKE_POSITION_INDEPENDENT_CODE ON)
endif()


###########################################################################
## Path variables
###########################################################################
# Derive an absolute path to the code generation anchor folder.
get_filename_component(START_DIR ../../.. ABSOLUTE)

# Special directories defined by using CACHE variables can be overridden 
# by setting the variable from the command line, e.g.,
# 
# 	cmake . -DMATLAB_ROOT=/path/to/another/matlab/root
set(MATLAB_ROOT /MATLAB CACHE PATH "")

# Additional variables that are defined conditionally.
if("${CMAKE_CURRENT_BINARY_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
    set(BINARY_START_DIR "${START_DIR}")
else()
    set(BINARY_START_DIR "${CMAKE_BINARY_DIR}")
endif()

###########################################################################
## System Libraries
###########################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES} ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

###########################################################################
## Target definition and commands
###########################################################################

# Definition of target "FFT".
add_library(FFT STATIC ${START_DIR}/codegen/lib/FFT/rt_nonfinite.c
    ${START_DIR}/codegen/lib/FFT/rtGetNaN.c
    ${START_DIR}/codegen/lib/FFT/rtGetInf.c
    ${START_DIR}/codegen/lib/FFT/FFT_initialize.c
    ${START_DIR}/codegen/lib/FFT/FFT_terminate.c
    ${START_DIR}/codegen/lib/FFT/FFT.c
    ${START_DIR}/codegen/lib/FFT/fft1.c
    ${START_DIR}/codegen/lib/FFT/FFTImplementationCallback.c
    ${START_DIR}/codegen/lib/FFT/abs.c
    ${START_DIR}/codegen/lib/FFT/FormBeam.c
    ${START_DIR}/codegen/lib/FFT/delayseq.c
    ${START_DIR}/codegen/lib/FFT/sum.c
    ${START_DIR}/codegen/lib/FFT/predictClass.c
    ${START_DIR}/codegen/lib/FFT/CompactClassificationNeuralNetwork.c
    ${START_DIR}/codegen/lib/FFT/FFT_emxutil.c
    ${START_DIR}/codegen/lib/FFT/FFT_emxAPI.c
    /SupportPackages/toolbox/realtime/targets/raspi/src/linuxtimelogger/linuxTimeLogger.c)

# Set properties for target "FFT".
set_target_properties(FFT PROPERTIES PREFIX ""
    RUNTIME_OUTPUT_DIRECTORY "${BINARY_START_DIR}/codegen/lib/FFT/$<0:>"
    LIBRARY_OUTPUT_DIRECTORY "${BINARY_START_DIR}/codegen/lib/FFT/$<0:>"
    ARCHIVE_OUTPUT_DIRECTORY "${BINARY_START_DIR}/codegen/lib/FFT/$<0:>")

# Specify language features required for target "FFT".
target_compile_features(FFT PUBLIC c_std_99)

# Specify compiler preprocessor definitions for target "FFT".
target_compile_definitions(FFT PRIVATE -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
    -D__linux__
    -DARM_PROJECT
    -D_USE_TARGET_UDP_
    -D_RUNONTARGETHARDWARE_BUILD_
    -DSTACK_SIZE=200000
    -DMODEL=FFT)

# Specify compiler flags for target "FFT".
target_compile_options(FFT PRIVATE -fopenmp)

# Specify include directories for target "FFT".
target_include_directories(FFT PUBLIC $<BUILD_INTERFACE:${START_DIR}/codegen/lib/FFT>
    $<INSTALL_INTERFACE:codegen/lib/FFT>
    $<BUILD_INTERFACE:${START_DIR}>
    $<INSTALL_INTERFACE:.>
    /SupportPackages/toolbox/realtime/targets/raspi/include
    $<BUILD_INTERFACE:${MATLAB_ROOT}/toolbox/coder/rtiostream/src/utils>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/extern/include>)

# Specify library link dependencies for target "FFT". CMake generator 
# expressions are used to create a CMakeLists.txt file that supports 
# multiple platforms with differently named system library dependencies.
target_link_libraries(FFT PUBLIC $<$<BOOL:${FOUND_LIBM}>:m>)
target_link_libraries(FFT INTERFACE ${LINUX_TARGET_LIBS_MACRO})


###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET FFT POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created STATIC library: $<TARGET_FILE:FFT>")

###########################################################################
## Call toolchain hook function if defined
###########################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(FFT)
endif()
