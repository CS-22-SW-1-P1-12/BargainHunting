# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\manta\Documents\GitHub\BargainHunting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug

# Include any dependencies generated for this target.
include src/CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/main.dir/flags.make

src/CMakeFiles/main.dir/main.c.obj: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/main.c.obj: ../src/main.c
src/CMakeFiles/main.dir/main.c.obj: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/main.dir/main.c.obj"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/main.c.obj -MF CMakeFiles\main.dir\main.c.obj.d -o CMakeFiles\main.dir\main.c.obj -c C:\Users\manta\Documents\GitHub\BargainHunting\src\main.c

src/CMakeFiles/main.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/main.c.i"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\manta\Documents\GitHub\BargainHunting\src\main.c > CMakeFiles\main.dir\main.c.i

src/CMakeFiles/main.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/main.c.s"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\manta\Documents\GitHub\BargainHunting\src\main.c -o CMakeFiles\main.dir\main.c.s

src/CMakeFiles/main.dir/database.c.obj: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/database.c.obj: ../src/database.c
src/CMakeFiles/main.dir/database.c.obj: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/main.dir/database.c.obj"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/database.c.obj -MF CMakeFiles\main.dir\database.c.obj.d -o CMakeFiles\main.dir\database.c.obj -c C:\Users\manta\Documents\GitHub\BargainHunting\src\database.c

src/CMakeFiles/main.dir/database.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/database.c.i"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\manta\Documents\GitHub\BargainHunting\src\database.c > CMakeFiles\main.dir\database.c.i

src/CMakeFiles/main.dir/database.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/database.c.s"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\manta\Documents\GitHub\BargainHunting\src\database.c -o CMakeFiles\main.dir\database.c.s

src/CMakeFiles/main.dir/preferences.c.obj: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/preferences.c.obj: ../src/preferences.c
src/CMakeFiles/main.dir/preferences.c.obj: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/main.dir/preferences.c.obj"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/preferences.c.obj -MF CMakeFiles\main.dir\preferences.c.obj.d -o CMakeFiles\main.dir\preferences.c.obj -c C:\Users\manta\Documents\GitHub\BargainHunting\src\preferences.c

src/CMakeFiles/main.dir/preferences.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/preferences.c.i"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\manta\Documents\GitHub\BargainHunting\src\preferences.c > CMakeFiles\main.dir\preferences.c.i

src/CMakeFiles/main.dir/preferences.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/preferences.c.s"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\manta\Documents\GitHub\BargainHunting\src\preferences.c -o CMakeFiles\main.dir\preferences.c.s

src/CMakeFiles/main.dir/grocery_list.c.obj: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/grocery_list.c.obj: ../src/grocery_list.c
src/CMakeFiles/main.dir/grocery_list.c.obj: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/main.dir/grocery_list.c.obj"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/grocery_list.c.obj -MF CMakeFiles\main.dir\grocery_list.c.obj.d -o CMakeFiles\main.dir\grocery_list.c.obj -c C:\Users\manta\Documents\GitHub\BargainHunting\src\grocery_list.c

src/CMakeFiles/main.dir/grocery_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/grocery_list.c.i"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\manta\Documents\GitHub\BargainHunting\src\grocery_list.c > CMakeFiles\main.dir\grocery_list.c.i

src/CMakeFiles/main.dir/grocery_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/grocery_list.c.s"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\manta\Documents\GitHub\BargainHunting\src\grocery_list.c -o CMakeFiles\main.dir\grocery_list.c.s

src/CMakeFiles/main.dir/calculations.c.obj: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/calculations.c.obj: ../src/calculations.c
src/CMakeFiles/main.dir/calculations.c.obj: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object src/CMakeFiles/main.dir/calculations.c.obj"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/calculations.c.obj -MF CMakeFiles\main.dir\calculations.c.obj.d -o CMakeFiles\main.dir\calculations.c.obj -c C:\Users\manta\Documents\GitHub\BargainHunting\src\calculations.c

src/CMakeFiles/main.dir/calculations.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/calculations.c.i"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\manta\Documents\GitHub\BargainHunting\src\calculations.c > CMakeFiles\main.dir\calculations.c.i

src/CMakeFiles/main.dir/calculations.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/calculations.c.s"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\manta\Documents\GitHub\BargainHunting\src\calculations.c -o CMakeFiles\main.dir\calculations.c.s

src/CMakeFiles/main.dir/sort_shopping_list.c.obj: src/CMakeFiles/main.dir/flags.make
src/CMakeFiles/main.dir/sort_shopping_list.c.obj: ../src/sort_shopping_list.c
src/CMakeFiles/main.dir/sort_shopping_list.c.obj: src/CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object src/CMakeFiles/main.dir/sort_shopping_list.c.obj"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/CMakeFiles/main.dir/sort_shopping_list.c.obj -MF CMakeFiles\main.dir\sort_shopping_list.c.obj.d -o CMakeFiles\main.dir\sort_shopping_list.c.obj -c C:\Users\manta\Documents\GitHub\BargainHunting\src\sort_shopping_list.c

src/CMakeFiles/main.dir/sort_shopping_list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/sort_shopping_list.c.i"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\manta\Documents\GitHub\BargainHunting\src\sort_shopping_list.c > CMakeFiles\main.dir\sort_shopping_list.c.i

src/CMakeFiles/main.dir/sort_shopping_list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/sort_shopping_list.c.s"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && C:\PROGRA~1\JETBRA~1\CLION2~1.4\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\manta\Documents\GitHub\BargainHunting\src\sort_shopping_list.c -o CMakeFiles\main.dir\sort_shopping_list.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.c.obj" \
"CMakeFiles/main.dir/database.c.obj" \
"CMakeFiles/main.dir/preferences.c.obj" \
"CMakeFiles/main.dir/grocery_list.c.obj" \
"CMakeFiles/main.dir/calculations.c.obj" \
"CMakeFiles/main.dir/sort_shopping_list.c.obj"

# External object files for target main
main_EXTERNAL_OBJECTS =

src/main.exe: src/CMakeFiles/main.dir/main.c.obj
src/main.exe: src/CMakeFiles/main.dir/database.c.obj
src/main.exe: src/CMakeFiles/main.dir/preferences.c.obj
src/main.exe: src/CMakeFiles/main.dir/grocery_list.c.obj
src/main.exe: src/CMakeFiles/main.dir/calculations.c.obj
src/main.exe: src/CMakeFiles/main.dir/sort_shopping_list.c.obj
src/main.exe: src/CMakeFiles/main.dir/build.make
src/main.exe: src/CMakeFiles/main.dir/linklibs.rsp
src/main.exe: src/CMakeFiles/main.dir/objects1.rsp
src/main.exe: src/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable main.exe"
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\main.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/main.dir/build: src/main.exe
.PHONY : src/CMakeFiles/main.dir/build

src/CMakeFiles/main.dir/clean:
	cd /d C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src && $(CMAKE_COMMAND) -P CMakeFiles\main.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/main.dir/clean

src/CMakeFiles/main.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\manta\Documents\GitHub\BargainHunting C:\Users\manta\Documents\GitHub\BargainHunting\src C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src C:\Users\manta\Documents\GitHub\BargainHunting\cmake-build-debug\src\CMakeFiles\main.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/main.dir/depend

