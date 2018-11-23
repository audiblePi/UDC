# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/newowner/workspace/_computational_geometry/CGAL/BiniazEtAl/UnitDiskCover

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/newowner/workspace/_computational_geometry/CGAL/BiniazEtAl/UnitDiskCover

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/CMake.app/Contents/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/Applications/CMake.app/Contents/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test

.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/Applications/CMake.app/Contents/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/newowner/workspace/_computational_geometry/CGAL/BiniazEtAl/UnitDiskCover/CMakeFiles /Users/newowner/workspace/_computational_geometry/CGAL/BiniazEtAl/UnitDiskCover/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/newowner/workspace/_computational_geometry/CGAL/BiniazEtAl/UnitDiskCover/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named executable

# Build rule for target.
executable: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 executable
.PHONY : executable

# fast build rule for target.
executable/fast:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/build
.PHONY : executable/fast

#=============================================================================
# Target rules for targets named ContinuousCoverage

# Build rule for target.
ContinuousCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousCoverage
.PHONY : ContinuousCoverage

# fast build rule for target.
ContinuousCoverage/fast:
	$(MAKE) -f CMakeFiles/ContinuousCoverage.dir/build.make CMakeFiles/ContinuousCoverage.dir/build
.PHONY : ContinuousCoverage/fast

#=============================================================================
# Target rules for targets named ContinuousTest

# Build rule for target.
ContinuousTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousTest
.PHONY : ContinuousTest

# fast build rule for target.
ContinuousTest/fast:
	$(MAKE) -f CMakeFiles/ContinuousTest.dir/build.make CMakeFiles/ContinuousTest.dir/build
.PHONY : ContinuousTest/fast

#=============================================================================
# Target rules for targets named ContinuousBuild

# Build rule for target.
ContinuousBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousBuild
.PHONY : ContinuousBuild

# fast build rule for target.
ContinuousBuild/fast:
	$(MAKE) -f CMakeFiles/ContinuousBuild.dir/build.make CMakeFiles/ContinuousBuild.dir/build
.PHONY : ContinuousBuild/fast

#=============================================================================
# Target rules for targets named ContinuousStart

# Build rule for target.
ContinuousStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousStart
.PHONY : ContinuousStart

# fast build rule for target.
ContinuousStart/fast:
	$(MAKE) -f CMakeFiles/ContinuousStart.dir/build.make CMakeFiles/ContinuousStart.dir/build
.PHONY : ContinuousStart/fast

#=============================================================================
# Target rules for targets named ExperimentalBuild

# Build rule for target.
ExperimentalBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalBuild
.PHONY : ExperimentalBuild

# fast build rule for target.
ExperimentalBuild/fast:
	$(MAKE) -f CMakeFiles/ExperimentalBuild.dir/build.make CMakeFiles/ExperimentalBuild.dir/build
.PHONY : ExperimentalBuild/fast

#=============================================================================
# Target rules for targets named ExperimentalCoverage

# Build rule for target.
ExperimentalCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalCoverage
.PHONY : ExperimentalCoverage

# fast build rule for target.
ExperimentalCoverage/fast:
	$(MAKE) -f CMakeFiles/ExperimentalCoverage.dir/build.make CMakeFiles/ExperimentalCoverage.dir/build
.PHONY : ExperimentalCoverage/fast

#=============================================================================
# Target rules for targets named ExperimentalSubmit

# Build rule for target.
ExperimentalSubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalSubmit
.PHONY : ExperimentalSubmit

# fast build rule for target.
ExperimentalSubmit/fast:
	$(MAKE) -f CMakeFiles/ExperimentalSubmit.dir/build.make CMakeFiles/ExperimentalSubmit.dir/build
.PHONY : ExperimentalSubmit/fast

#=============================================================================
# Target rules for targets named ContinuousUpdate

# Build rule for target.
ContinuousUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousUpdate
.PHONY : ContinuousUpdate

# fast build rule for target.
ContinuousUpdate/fast:
	$(MAKE) -f CMakeFiles/ContinuousUpdate.dir/build.make CMakeFiles/ContinuousUpdate.dir/build
.PHONY : ContinuousUpdate/fast

#=============================================================================
# Target rules for targets named ExperimentalUpdate

# Build rule for target.
ExperimentalUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalUpdate
.PHONY : ExperimentalUpdate

# fast build rule for target.
ExperimentalUpdate/fast:
	$(MAKE) -f CMakeFiles/ExperimentalUpdate.dir/build.make CMakeFiles/ExperimentalUpdate.dir/build
.PHONY : ExperimentalUpdate/fast

#=============================================================================
# Target rules for targets named ExperimentalStart

# Build rule for target.
ExperimentalStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalStart
.PHONY : ExperimentalStart

# fast build rule for target.
ExperimentalStart/fast:
	$(MAKE) -f CMakeFiles/ExperimentalStart.dir/build.make CMakeFiles/ExperimentalStart.dir/build
.PHONY : ExperimentalStart/fast

#=============================================================================
# Target rules for targets named ContinuousSubmit

# Build rule for target.
ContinuousSubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousSubmit
.PHONY : ContinuousSubmit

# fast build rule for target.
ContinuousSubmit/fast:
	$(MAKE) -f CMakeFiles/ContinuousSubmit.dir/build.make CMakeFiles/ContinuousSubmit.dir/build
.PHONY : ContinuousSubmit/fast

#=============================================================================
# Target rules for targets named ExperimentalTest

# Build rule for target.
ExperimentalTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalTest
.PHONY : ExperimentalTest

# fast build rule for target.
ExperimentalTest/fast:
	$(MAKE) -f CMakeFiles/ExperimentalTest.dir/build.make CMakeFiles/ExperimentalTest.dir/build
.PHONY : ExperimentalTest/fast

#=============================================================================
# Target rules for targets named NightlySubmit

# Build rule for target.
NightlySubmit: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlySubmit
.PHONY : NightlySubmit

# fast build rule for target.
NightlySubmit/fast:
	$(MAKE) -f CMakeFiles/NightlySubmit.dir/build.make CMakeFiles/NightlySubmit.dir/build
.PHONY : NightlySubmit/fast

#=============================================================================
# Target rules for targets named NightlyMemCheck

# Build rule for target.
NightlyMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyMemCheck
.PHONY : NightlyMemCheck

# fast build rule for target.
NightlyMemCheck/fast:
	$(MAKE) -f CMakeFiles/NightlyMemCheck.dir/build.make CMakeFiles/NightlyMemCheck.dir/build
.PHONY : NightlyMemCheck/fast

#=============================================================================
# Target rules for targets named ExperimentalConfigure

# Build rule for target.
ExperimentalConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalConfigure
.PHONY : ExperimentalConfigure

# fast build rule for target.
ExperimentalConfigure/fast:
	$(MAKE) -f CMakeFiles/ExperimentalConfigure.dir/build.make CMakeFiles/ExperimentalConfigure.dir/build
.PHONY : ExperimentalConfigure/fast

#=============================================================================
# Target rules for targets named NightlyCoverage

# Build rule for target.
NightlyCoverage: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyCoverage
.PHONY : NightlyCoverage

# fast build rule for target.
NightlyCoverage/fast:
	$(MAKE) -f CMakeFiles/NightlyCoverage.dir/build.make CMakeFiles/NightlyCoverage.dir/build
.PHONY : NightlyCoverage/fast

#=============================================================================
# Target rules for targets named NightlyTest

# Build rule for target.
NightlyTest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyTest
.PHONY : NightlyTest

# fast build rule for target.
NightlyTest/fast:
	$(MAKE) -f CMakeFiles/NightlyTest.dir/build.make CMakeFiles/NightlyTest.dir/build
.PHONY : NightlyTest/fast

#=============================================================================
# Target rules for targets named ContinuousMemCheck

# Build rule for target.
ContinuousMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousMemCheck
.PHONY : ContinuousMemCheck

# fast build rule for target.
ContinuousMemCheck/fast:
	$(MAKE) -f CMakeFiles/ContinuousMemCheck.dir/build.make CMakeFiles/ContinuousMemCheck.dir/build
.PHONY : ContinuousMemCheck/fast

#=============================================================================
# Target rules for targets named NightlyBuild

# Build rule for target.
NightlyBuild: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyBuild
.PHONY : NightlyBuild

# fast build rule for target.
NightlyBuild/fast:
	$(MAKE) -f CMakeFiles/NightlyBuild.dir/build.make CMakeFiles/NightlyBuild.dir/build
.PHONY : NightlyBuild/fast

#=============================================================================
# Target rules for targets named NightlyConfigure

# Build rule for target.
NightlyConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyConfigure
.PHONY : NightlyConfigure

# fast build rule for target.
NightlyConfigure/fast:
	$(MAKE) -f CMakeFiles/NightlyConfigure.dir/build.make CMakeFiles/NightlyConfigure.dir/build
.PHONY : NightlyConfigure/fast

#=============================================================================
# Target rules for targets named NightlyUpdate

# Build rule for target.
NightlyUpdate: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyUpdate
.PHONY : NightlyUpdate

# fast build rule for target.
NightlyUpdate/fast:
	$(MAKE) -f CMakeFiles/NightlyUpdate.dir/build.make CMakeFiles/NightlyUpdate.dir/build
.PHONY : NightlyUpdate/fast

#=============================================================================
# Target rules for targets named NightlyMemoryCheck

# Build rule for target.
NightlyMemoryCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyMemoryCheck
.PHONY : NightlyMemoryCheck

# fast build rule for target.
NightlyMemoryCheck/fast:
	$(MAKE) -f CMakeFiles/NightlyMemoryCheck.dir/build.make CMakeFiles/NightlyMemoryCheck.dir/build
.PHONY : NightlyMemoryCheck/fast

#=============================================================================
# Target rules for targets named ContinuousConfigure

# Build rule for target.
ContinuousConfigure: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ContinuousConfigure
.PHONY : ContinuousConfigure

# fast build rule for target.
ContinuousConfigure/fast:
	$(MAKE) -f CMakeFiles/ContinuousConfigure.dir/build.make CMakeFiles/ContinuousConfigure.dir/build
.PHONY : ContinuousConfigure/fast

#=============================================================================
# Target rules for targets named Nightly

# Build rule for target.
Nightly: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Nightly
.PHONY : Nightly

# fast build rule for target.
Nightly/fast:
	$(MAKE) -f CMakeFiles/Nightly.dir/build.make CMakeFiles/Nightly.dir/build
.PHONY : Nightly/fast

#=============================================================================
# Target rules for targets named NightlyStart

# Build rule for target.
NightlyStart: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 NightlyStart
.PHONY : NightlyStart

# fast build rule for target.
NightlyStart/fast:
	$(MAKE) -f CMakeFiles/NightlyStart.dir/build.make CMakeFiles/NightlyStart.dir/build
.PHONY : NightlyStart/fast

#=============================================================================
# Target rules for targets named ExperimentalMemCheck

# Build rule for target.
ExperimentalMemCheck: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ExperimentalMemCheck
.PHONY : ExperimentalMemCheck

# fast build rule for target.
ExperimentalMemCheck/fast:
	$(MAKE) -f CMakeFiles/ExperimentalMemCheck.dir/build.make CMakeFiles/ExperimentalMemCheck.dir/build
.PHONY : ExperimentalMemCheck/fast

#=============================================================================
# Target rules for targets named Continuous

# Build rule for target.
Continuous: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Continuous
.PHONY : Continuous

# fast build rule for target.
Continuous/fast:
	$(MAKE) -f CMakeFiles/Continuous.dir/build.make CMakeFiles/Continuous.dir/build
.PHONY : Continuous/fast

#=============================================================================
# Target rules for targets named Experimental

# Build rule for target.
Experimental: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Experimental
.PHONY : Experimental

# fast build rule for target.
Experimental/fast:
	$(MAKE) -f CMakeFiles/Experimental.dir/build.make CMakeFiles/Experimental.dir/build
.PHONY : Experimental/fast

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/main.cpp.s
.PHONY : main.cpp.s

src/BiniazEtAls.o: src/BiniazEtAls.cpp.o

.PHONY : src/BiniazEtAls.o

# target to build an object file
src/BiniazEtAls.cpp.o:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/BiniazEtAls.cpp.o
.PHONY : src/BiniazEtAls.cpp.o

src/BiniazEtAls.i: src/BiniazEtAls.cpp.i

.PHONY : src/BiniazEtAls.i

# target to preprocess a source file
src/BiniazEtAls.cpp.i:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/BiniazEtAls.cpp.i
.PHONY : src/BiniazEtAls.cpp.i

src/BiniazEtAls.s: src/BiniazEtAls.cpp.s

.PHONY : src/BiniazEtAls.s

# target to generate assembly for a file
src/BiniazEtAls.cpp.s:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/BiniazEtAls.cpp.s
.PHONY : src/BiniazEtAls.cpp.s

src/LRUDC.o: src/LRUDC.cpp.o

.PHONY : src/LRUDC.o

# target to build an object file
src/LRUDC.cpp.o:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/LRUDC.cpp.o
.PHONY : src/LRUDC.cpp.o

src/LRUDC.i: src/LRUDC.cpp.i

.PHONY : src/LRUDC.i

# target to preprocess a source file
src/LRUDC.cpp.i:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/LRUDC.cpp.i
.PHONY : src/LRUDC.cpp.i

src/LRUDC.s: src/LRUDC.cpp.s

.PHONY : src/LRUDC.s

# target to generate assembly for a file
src/LRUDC.cpp.s:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/LRUDC.cpp.s
.PHONY : src/LRUDC.cpp.s

src/LRUDC_Shift.o: src/LRUDC_Shift.cpp.o

.PHONY : src/LRUDC_Shift.o

# target to build an object file
src/LRUDC_Shift.cpp.o:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/LRUDC_Shift.cpp.o
.PHONY : src/LRUDC_Shift.cpp.o

src/LRUDC_Shift.i: src/LRUDC_Shift.cpp.i

.PHONY : src/LRUDC_Shift.i

# target to preprocess a source file
src/LRUDC_Shift.cpp.i:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/LRUDC_Shift.cpp.i
.PHONY : src/LRUDC_Shift.cpp.i

src/LRUDC_Shift.s: src/LRUDC_Shift.cpp.s

.PHONY : src/LRUDC_Shift.s

# target to generate assembly for a file
src/LRUDC_Shift.cpp.s:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/LRUDC_Shift.cpp.s
.PHONY : src/LRUDC_Shift.cpp.s

src/UnitDiskCoverCenters.o: src/UnitDiskCoverCenters.cpp.o

.PHONY : src/UnitDiskCoverCenters.o

# target to build an object file
src/UnitDiskCoverCenters.cpp.o:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/UnitDiskCoverCenters.cpp.o
.PHONY : src/UnitDiskCoverCenters.cpp.o

src/UnitDiskCoverCenters.i: src/UnitDiskCoverCenters.cpp.i

.PHONY : src/UnitDiskCoverCenters.i

# target to preprocess a source file
src/UnitDiskCoverCenters.cpp.i:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/UnitDiskCoverCenters.cpp.i
.PHONY : src/UnitDiskCoverCenters.cpp.i

src/UnitDiskCoverCenters.s: src/UnitDiskCoverCenters.cpp.s

.PHONY : src/UnitDiskCoverCenters.s

# target to generate assembly for a file
src/UnitDiskCoverCenters.cpp.s:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/UnitDiskCoverCenters.cpp.s
.PHONY : src/UnitDiskCoverCenters.cpp.s

src/UnitDiskCoverPrinter.o: src/UnitDiskCoverPrinter.cpp.o

.PHONY : src/UnitDiskCoverPrinter.o

# target to build an object file
src/UnitDiskCoverPrinter.cpp.o:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/UnitDiskCoverPrinter.cpp.o
.PHONY : src/UnitDiskCoverPrinter.cpp.o

src/UnitDiskCoverPrinter.i: src/UnitDiskCoverPrinter.cpp.i

.PHONY : src/UnitDiskCoverPrinter.i

# target to preprocess a source file
src/UnitDiskCoverPrinter.cpp.i:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/UnitDiskCoverPrinter.cpp.i
.PHONY : src/UnitDiskCoverPrinter.cpp.i

src/UnitDiskCoverPrinter.s: src/UnitDiskCoverPrinter.cpp.s

.PHONY : src/UnitDiskCoverPrinter.s

# target to generate assembly for a file
src/UnitDiskCoverPrinter.cpp.s:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/UnitDiskCoverPrinter.cpp.s
.PHONY : src/UnitDiskCoverPrinter.cpp.s

src/UnitDiskCoverUnitGrid.o: src/UnitDiskCoverUnitGrid.cpp.o

.PHONY : src/UnitDiskCoverUnitGrid.o

# target to build an object file
src/UnitDiskCoverUnitGrid.cpp.o:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/UnitDiskCoverUnitGrid.cpp.o
.PHONY : src/UnitDiskCoverUnitGrid.cpp.o

src/UnitDiskCoverUnitGrid.i: src/UnitDiskCoverUnitGrid.cpp.i

.PHONY : src/UnitDiskCoverUnitGrid.i

# target to preprocess a source file
src/UnitDiskCoverUnitGrid.cpp.i:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/UnitDiskCoverUnitGrid.cpp.i
.PHONY : src/UnitDiskCoverUnitGrid.cpp.i

src/UnitDiskCoverUnitGrid.s: src/UnitDiskCoverUnitGrid.cpp.s

.PHONY : src/UnitDiskCoverUnitGrid.s

# target to generate assembly for a file
src/UnitDiskCoverUnitGrid.cpp.s:
	$(MAKE) -f CMakeFiles/executable.dir/build.make CMakeFiles/executable.dir/src/UnitDiskCoverUnitGrid.cpp.s
.PHONY : src/UnitDiskCoverUnitGrid.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... executable"
	@echo "... ContinuousCoverage"
	@echo "... ContinuousTest"
	@echo "... ContinuousBuild"
	@echo "... ContinuousStart"
	@echo "... ExperimentalBuild"
	@echo "... ExperimentalCoverage"
	@echo "... ExperimentalSubmit"
	@echo "... ContinuousUpdate"
	@echo "... ExperimentalUpdate"
	@echo "... ExperimentalStart"
	@echo "... ContinuousSubmit"
	@echo "... ExperimentalTest"
	@echo "... NightlySubmit"
	@echo "... NightlyMemCheck"
	@echo "... test"
	@echo "... ExperimentalConfigure"
	@echo "... NightlyCoverage"
	@echo "... NightlyTest"
	@echo "... ContinuousMemCheck"
	@echo "... NightlyBuild"
	@echo "... NightlyConfigure"
	@echo "... NightlyUpdate"
	@echo "... edit_cache"
	@echo "... NightlyMemoryCheck"
	@echo "... ContinuousConfigure"
	@echo "... Nightly"
	@echo "... NightlyStart"
	@echo "... ExperimentalMemCheck"
	@echo "... Continuous"
	@echo "... Experimental"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... src/BiniazEtAls.o"
	@echo "... src/BiniazEtAls.i"
	@echo "... src/BiniazEtAls.s"
	@echo "... src/LRUDC.o"
	@echo "... src/LRUDC.i"
	@echo "... src/LRUDC.s"
	@echo "... src/LRUDC_Shift.o"
	@echo "... src/LRUDC_Shift.i"
	@echo "... src/LRUDC_Shift.s"
	@echo "... src/UnitDiskCoverCenters.o"
	@echo "... src/UnitDiskCoverCenters.i"
	@echo "... src/UnitDiskCoverCenters.s"
	@echo "... src/UnitDiskCoverPrinter.o"
	@echo "... src/UnitDiskCoverPrinter.i"
	@echo "... src/UnitDiskCoverPrinter.s"
	@echo "... src/UnitDiskCoverUnitGrid.o"
	@echo "... src/UnitDiskCoverUnitGrid.i"
	@echo "... src/UnitDiskCoverUnitGrid.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

