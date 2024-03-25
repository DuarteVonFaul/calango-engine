#ifndef CALANGO_PLATFORM_H
  #define CALANGO_PLATFORM_H

  #ifdef _WIN32
    #define STB_IMAGE_IMPLEMENTATION
    #include <windows.h>
    #include <vector>


    #include <GLFW/glfw3.h>
    #include <GL/GLU.h>
    #include <calango/primitives.hpp>
    #include <calango/color.hpp>
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

    struct CALANGO_PLATFORM_API Draw final{
      Draw(int);
      int amount;

      void Triangle(unsigned int id, clg::vec3 p1,clg::vec3 p2,clg::vec3 p3, clg::color color);
      void Cube(unsigned int id, float s);
      void Rect(unsigned int id, clg::vec3 p1,clg::vec3 p2,clg::vec3 p3,clg::vec3 p4, clg::color color);
      void Rect(clg::vec3 p1,clg::vec3 p2,clg::vec3 p3,clg::vec3 p4, clg::color color);
      void Sphere(unsigned int id, GLfloat radius, GLuint nStacks, GLuint nSectores, clg::color color, bool X_RAY_MODE = false);
      void orientationPlane(unsigned int id, bool _2D = false);
      void drawIndetity();
      void getInstance(int id);
      void deleteInstace(int id, int interval = 1);
      void deleteAllInstances();
      void newDraw();
      void endDraw();

      void translate(clg::vec3 vector);
      void Rotate(clg::vec4 vector);
      void Scale(clg::vec3 vector);
      void drawScreen(GLFWwindow* window);

    };

    //Contexto OpenGl criar uma Tela com GLFW 
    struct CALANGO_PLATFORM_API ScreenBuilder final
    {
        ScreenBuilder();
        void showMensage(const char* message);
        GLFWwindow* createWindow(int width, int height, const char* title);

        void destroyWindow(GLFWwindow* window);
        bool initOpenGL(GLFWwindow* window);
        void updateWindowEvents(GLFWwindow* window);
        bool getWindowCloseFlag(GLFWwindow* window);
        void clearWindowCloseFlag(GLFWwindow* window);

        void windowProjection(GLFWwindow* window);
        void clearColorWindow(vec4 clear_color = vec4(0.0f, 0.0f, 0.0f, 1.00f));
        void clearWindow(GLFWwindow* window);

    };

    //Contexto OpenGL Criar SubTelas com ImGUI
    struct CALANGO_PLATFORM_API ScreenManager final
    {
        ScreenManager();


    };


    

  } 

#endif  //CALANGO_PLATFORM_H