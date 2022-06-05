cmake_minimum_required(VERSION 3.10)
cmake_minimum_required(VERSION 3.10)

project(PdfLibrary)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# specify the all files property
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Static Library output directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Build/lib/static")

# Library output directory
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Build/lib/dynamic")

# Binary or Dll output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Build/bin")

set(Proj_Inc_Dirs
	"${CMAKE_CURRENT_SOURCE_DIR}/include"
)

set(Lib_Name
	"pdflib"
)

add_subdirectory("include")
add_subdirectory("src")

add_dependencies(app pdflib)

set_target_properties(pdflib PROPERTIES LINKER_LANGUAGE CXX)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT app)

set_property(TARGET app PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}")