message(STATUS "Building ${Lib_Name}")

include_directories(${Proj_Inc_Dirs})

link_directories(${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

file(GLOB src_files
	"*.h"
	"*.cpp"
	"src/*.h"
	"src/*.hpp"
	"src/*.cpp"
	"src/decoder/*.h"
	"src/decoder/*.hpp"
	"src/decoder/*.cpp"
)

add_library(${Lib_Name}
    ${src_files}
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${src_files})