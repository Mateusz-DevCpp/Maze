find_library(SFML_LIBRARY "SFML" "/usr/lib" "/usr/local/lib")
find_path(SFML_INCLUDE_DIR "SFML/Graphics.hpp" "/usr/include" "/usr/local/include")

if((NOT SFML_LIBRARY) OR (NOT SFML_INCLUDE_DIR))
	set(SFML_DIR "${THIRDPARTY_DIR}/SFML")

	message("Unable to find SFML, cloning...")
    execute_process(COMMAND git submodule update --init ${SFML_DIR}
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

    add_subdirectory("${SFML_DIR}")

	set(SFML_LIBRARY "SFML/lib" "${SFML_LIBRARIES}")
	set(SFML_INCLUDE_DIR "${SFML_DIR}/include")
endif()