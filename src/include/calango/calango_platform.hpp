#ifndef CALANGO_PLATFORM_H
  #define CALANGO_PLATFORM_H

  #ifdef _WIN32
    #define STB_IMAGE_IMPLEMENTATION
    #include <windows.h>
    #include <iostream>
    #include <vector>
    #include <cmath>

    #include "../lib/imgui/imgui.h"
    #include "../lib/imgui/imgui_impl_glfw.h"
    #include "../lib/imgui/imgui_impl_opengl3.h"

    #include <GLFW/glfw3.h>
    #include <GL/GLU.h>
    #include <calango/primitives.hpp>
    #include <calango/color.hpp>
 
    #define CALANGO_PLATFORM_WINDOWS
  #elif __linux__
    #include <stdlib.h>
    #include <string.h>
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
  #endif // CALANGO_PLATFORM_WINDOWS   #include <iostream>



  namespace clg
  {

    struct CALANGO_PLATFORM_API DrawManager final{
      DrawManager(int);
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

    //Contexto OpenGL Criar SubTelas com ImGUI
    struct CALANGO_PLATFORM_API GuiManager final
    {
        GuiManager();
        ImGuiContext* initOpenGL(GLFWwindow* window);
        void openRender(ImGuiContext* igContext);
        void closeRender(ImGuiContext* igContext);
        void openScreen(ImGuiContext* igContext,
                        const char* title, 
                        clg::vec2 pos, 
                        clg::vec2 size);

        void openScreen(ImGuiContext* igContext, 
                        int &width,
                        int &height, 
                        const char* title, 
                        float anchor_x,float anchor_y,
                        float size_x,float size_y, 
                        ImGuiWindowFlags window_flags = 0);
                        
        void closeScreen(ImGuiContext* igContext);
        //GUI
        void renderButton(clg::vec2 anchor, 
                          clg::vec2 size,
                          std::string text,
                          MethodCallback callback);

        void renderLabel(clg::vec2 anchor, 
                          clg::vec2 size,
                          std::string text);

        void renderTextArea(clg::vec2 anchor, 
                            clg::vec2 size,
                            const char textTitle[100], 
                            std::string* textBuffer,
                            MethodCallback callback);

        void renderCheckBox(clg::vec2 anchor, 
                            clg::vec2 size,
                            std::string text,
                            bool*  checkBoxValue);

        void renderTree(const char* name,MethodCallback callback);
        void renderSameLine();
        void renderSmallButton(const char* name,MethodCallback callback);
        void renderSelectable(const char* name,int *current_select, int id);
        void renderMenuBar();
        std::string glsl_version;

    };

    struct CALANGO_PLATFORM_API Window final{

        int width;
        int height;
        clg::vec4 viewportPresets;

        ImGuiContext* GuiContext;
        GLFWwindow* windowContext;
        
        void OnGui(clg::GuiManager* gui);

    };

     //Contexto OpenGl criar uma Tela com GLFW 
    struct CALANGO_PLATFORM_API WindowManager final
    {
        WindowManager();
        void showMensage(const char* message);
        GLFWwindow* createWindow(int width, int height, const char* title);

        void destroyWindow(GLFWwindow* window);
        bool initOpenGL(GLFWwindow* window);
        void updateWindowEvents(GLFWwindow* window);
        bool getWindowCloseFlag(GLFWwindow* window);
        void clearWindowCloseFlag(GLFWwindow* window);

        void windowProjection(Window* window);
        void windowProjection(Window* window, clg::vec2 anchor, clg::vec2 size);
        void clearColorWindow(vec4 clear_color = vec4(0.0f, 0.0f, 0.0f, 1.00f));
        void clearWindow(GLFWwindow* window);

    };


    class Camera
    { 
      private:
        vec3 m_pos;
        vec3 m_up;
        vec3 m_left;
        vec3 m_dir;
      public:
        Camera(vec3 _pos, vec3 _up, vec3 _left, vec3 _dir):m_pos(_pos), m_up(_up), m_left(_left), m_dir(_dir){};
        void activate()
        {
          vec3 look = m_pos + m_dir;
          gluLookAt(m_pos.x,m_pos.y,m_pos.z,
                    look.x,look.y,look.z,
                    m_up.x, m_up.y, m_up.z);
        };

    };
    

    class Camera2D: public Camera
    {
      public:
        Camera2D(vec2 _pos):Camera(vec3(_pos.x,_pos.y,50.0),vec3(0,1,0),vec3(-1,0,0),vec3(0,0,-1)){};

    };

  } 

#endif  //CALANGO_PLATFORM_H