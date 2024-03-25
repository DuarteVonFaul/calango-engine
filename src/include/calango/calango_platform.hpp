#ifndef CALANGO_PLATFORM_H
  #define CALANGO_PLATFORM_H

  #ifdef _WIN32
    #define STB_IMAGE_IMPLEMENTATION
    #include <windows.h>
    #include <GLFW/glfw3.h>
    #include <GL/GLU.h>
    #include "../imgui/imgui.h"
    #include "../imgui/imgui_impl_glfw.h"
    #include "../imgui/imgui_impl_opengl3.h"
    #define CALANGO_PLATFORM_WINDOWS
  #elif __linux__
    #include <stdlib.h>
    #include <string.h>
    #include <GLFW/glfw3.h>
    #include <gl/GLU.h>
    #define CALANGO_PLATFORM_LINUX
  #else
    #define CALANGO_PLATFORM_UNKNOWN
    #error "Unsuported platform"
  #endif

  #ifdef CALANGO_PLATFORM_WINDOWS
    #ifdef CALANGO_PLATFORM_IMPLEMENTATION
      #define CALANGO_PLATFORM_API __declspec(dllexport)
    #else
      #define CALANGO_PLATFORM_API __declspec(dllimport)
    #endif //CALANGO_PLATFORM_IMPLEMENTATION WIN
  #else
    #define CALANGO_PLATFORM_API
  #endif // CALANGO_PLATFORM_WINDOWS

  namespace clg
  {
     struct CALANGO_PLATFORM_API Platform final
     {

     }
  } 

#endif  //CALANGO_PLATFORM_H