add_executable(act_map_test
    act_map_test.cpp)
    
set_target_properties(act_map_test PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(act_map_test
    act_map
    Catch
)