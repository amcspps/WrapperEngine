cmake_minimum_required (VERSION 3.8)

project ("WrapperEngine")

add_executable (WrapperEngine "main.cpp"  "Wrapper.cpp" "Engine.cpp" "Wrapper.h" "Engine.h" "Subject.cpp" "Subject.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET WrapperEngine PROPERTY CXX_STANDARD 20)
endif()

