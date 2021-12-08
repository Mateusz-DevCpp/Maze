# Add source files
file(GLOB_RECURSE SOURCE_FILES 
	 *.c
	 *.cpp)
	
# Add header files
file(GLOB_RECURSE HEADER_FILES 
	 *.h
	 *.hpp)

include_directories(include)
include_directories(include/Player)

# Define the executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)

# Define the include DIRs
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC "${SFML_INCLUDE_DIR}")

target_link_libraries(${PROJECT_NAME} "sfml-graphics")
target_link_libraries(${PROJECT_NAME} "sfml-window")
target_link_libraries(${PROJECT_NAME} "sfml-system")


add_custom_command(TARGET  ${PROJECT_NAME} POST_BUILD
				   COMMAND ${CMAKE_COMMAND} -E copy_directory
						   ${CMAKE_SOURCE_DIR}/Data
						   ${CMAKE_CURRENT_BINARY_DIR}/Data)