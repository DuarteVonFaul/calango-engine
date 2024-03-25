cmake_minimum_required(VERSION 3.28)
project(OPENGLTT VERSION 0.1.0 LANGUAGES CXX)

# Validando Plataforma
if (UNIX)
    set(PLATFORM linux CACHE STRING "Target platform" FORCE)
elseif (WIN32)
    set(PLATFORM win64 CACHE STRING "Target platform" FORCE)
else ()
    message(FATAL_ERROR "Plataforma não suportada")
endif()

#Definindo dependencias
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

#caminho raiz do projeto
set(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)




# criação dos diretorios do SDK
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/calangoSDK/lib 
  CACHE PATH "Output directory for static libraries.")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/calangoSDK/lib
  CACHE PATH "Output directory for shared libraries.")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/calangoSDK/bin
  CACHE PATH "Output directory for executables and DLL's.")

# Arquivos de saída de diretório para geradores multiconfig
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
  string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
  set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_BINARY_DIR}/calangoSDK/bin" CACHE PATH "" FORCE)
  set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_BINARY_DIR}/calangoSDK/lib" CACHE PATH "" FORCE)
  set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} "${CMAKE_BINARY_DIR}/calangoSDK/lib" CACHE PATH "" FORCE)
endforeach()






#IMGUI CONFIGURACAO----------------------------------------------------
# Defina o diretório onde estão localizados os arquivos imgui*.cpp
set(IMGUI_SOURCE_DIR ${SOURCE_PATH}/lib/imgui)
# Adicione todos os arquivos imgui*.cpp ao seu projeto
file(GLOB IMGUI_SOURCES
    ${IMGUI_SOURCE_DIR}/*.cpp
)
#CONFIGURACAO DO PROJETO------------------------------------------------
# Adicione seus diretórios de inclusão
include_directories(
    ${SOURCE_PATH}/include
)


#Gerar Executavel
add_executable(clauncher WIN32 ${SOURCE_PATH}/calango_launcher.cpp "${CALANGO_WINDOWS_RESOURCE_FILE}" )
target_include_directories(executavel PRIVATE ${IMGUI_SOURCE_DIR})
target_link_libraries(executavel PRIVATE OpenGL::GL glfw gdi32 glu32.lib )