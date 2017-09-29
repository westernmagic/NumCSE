set (MathGL2_DIR ${PROJECT_ROOT_DIR}/external/MathGL/mathgl-2x)
list (APPEND CMAKE_MODULE_PATH ${MathGL2_DIR}/scripts)
list (APPEND CMAKE_PREFIX_PATH ${MathGL2_DIR})
set (MATHGL2_LIBRARY_DIR ${MathGL2_DIR}/src)

# FindMathGL2.cmake FATAL_ERROR's even when using QUIET...
# so avoid doing that if we dont find the config file, which contains the version info
find_file (MathGL2_CONFIG_H NAMES mgl2/config.h)
if (EXISTS ${MathGL2_CONFIG_H})
	find_package (MathGL2 QUIET MODULE)
endif ()

if (NOT MathGL2_FOUND)
	message(STATUS "Building MathGL2...")
	execute_process (COMMAND
		${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" -DMGL_HAVE_C99_COMPLEX=0 .
		WORKING_DIRECTORY ${MathGL2_DIR}
		OUTPUT_QUIET
		ERROR_QUIET
	)

	execute_process (COMMAND
		${CMAKE_COMMAND} --build .
		WORKING_DIRECTORY ${MathGL2_DIR}
		OUTPUT_QUIET
		ERROR_QUIET
	)

	find_package (MathGL2 REQUIRED MODULE)
endif (NOT MathGL2_FOUND)

if (MathGL2_FOUND AND NOT TARGET MathGL2::MathGL2)
	add_library (MathGL2::MathGL2 INTERFACE IMPORTED)
	
	set_property (TARGET MathGL2::MathGL2 PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${MATHGL2_INCLUDE_DIRS})
	set_property (TARGET MathGL2::MathGL2 PROPERTY INTERFACE_LINK_LIBRARIES ${MATHGL2_LIBRARIES} ${LIBIGL_EXTRA_LIBRARIES})
endif (MathGL2_FOUND AND NOT TARGET MathGL2::MathGL2)

