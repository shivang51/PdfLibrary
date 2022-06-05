set(App_Name "app")

message(STATUS "Building ${App_Name}")

include_directories(${Proj_Inc_Dirs})

link_directories(${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

file(GLOB src_files
	"*.h"
	"*.cpp"
	"src/*.h"
	"src/*.hpp"
	"src/*.cpp"
)

add_executable(${App_Name}
	${src_files}
)

target_link_libraries(${App_Name} ${Lib_Name})

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${src_files})