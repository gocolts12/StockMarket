cmake_minimum_required(VERSION 3.14)
project(stonks)

set(CMAKE_CXX_STANDARD 14)

if (WIN32)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

include_directories(stonks/source)
include_directories(stonks/header)

# Your library sources go here
set(LIBRARY_SOURCES stonks/source/Stock.cpp stonks/source/StockMarket.cpp stonks/source/main.cpp stonks/source/Investor.cpp)
set(LIBRARY_HEADERS stonks/header/Stock.h stonks/header/StockMarket.h stonks/header/Investor.h )

add_library(stonk_library ${LIBRARY_SOURCES} ${LIBRARY_HEADERS}) 

# exec sources go here
set(EXEC_SOURCES stonks/source/main.cpp)

#add_executable(take_home_test ${EXEC_SOURCES} ${take_home_test_library}) 
#target_link_libraries(take_home_test take_home_test_library)

# Tests
#enable_testing()

# Your tests
#set(TEST_SOURCES test/tests.cpp)

add_executable(main_run ${LIBRARY_SOURCES} ${LIBRARY_HEADER})

#target_link_libraries(unit_tests take_home_test_library)

#add_test(unit_tests unit_tests)