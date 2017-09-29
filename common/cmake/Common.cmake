if (NOT DEFINED GUARD_${CMAKE_CURRENT_LIST_FILE})
	set (GUARD_${CMAKE_CURRENT_LIST_FILE} TRUE)
	list (APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})

	include (CommonHeader)
	include (Settings)

	include (MyBackward)
	include (MyThreads)
	#include (MyOpenMP)
	include (MyEigen)
	include (MyMathGL2)

	include (Submission)
endif (NOT DEFINED GUARD_${CMAKE_CURRENT_LIST_FILE})

