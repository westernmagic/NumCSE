find_package (OpenMP)
if (OPENMP_FOUND)
	set (CMAKE_C_FLAGS       "${CMAKE_C_FLAGS}       ${OpenMP_C_FLAGS}")
	set (CMAKE_CXX_FLAGS     "${CMAKE_CXX_FLAGS}     ${OpenMP_CXX_FLAGS}")
	set (CMAKE_FORTRAN_FLAGS "${CMAKE_FORTRAN_FLAGS} ${OpenMP_Fortran_FLAGS}")
endif (OPENMP_FOUND)
