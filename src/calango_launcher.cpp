#include <calango/calango.hpp>
#include <calango/calango_engine.hpp>
#include <calango/calango_platform.hpp>

namespace clg
{
  namespace launcher
  {
    int calangoMain(int argc, char** argv)
    {
      

      Engine engine;
      ScreenBuilder sBuild = engine.screenBuilder;
      ScreenManager sManager = engine.screenManager;
      Draw draw = Draw(2);

      int w,h;
      w = 1280;
      h = 720;

      GLFWwindow* window = sBuild.createWindow(1280,720,"Game Engine");
      sBuild.initOpenGL(window);
      sManager.initOpenGL(window);

      sBuild.clearColorWindow();
      draw.Cube(2,10.0);
      draw.orientationPlane(1);
      clg::Camera2D camera = clg::Camera2D(clg::vec2(0,0));

      float angulo = 0.0;

      while(!sBuild.getWindowCloseFlag(window))
      {
        sBuild.updateWindowEvents(window);

        sManager.openRender();
        sManager.openScreen("Scene",clg::vec2(0,0),clg::vec2(w/4,h/2));
        sManager.closeScreen();
        sManager.openScreen("Arquivos",clg::vec2(0,h/2),clg::vec2(w/4,h/2));
        sManager.closeScreen();
        sManager.openScreen("Arquivos",clg::vec2(float((w/4)*3),h/2),clg::vec2(w/4,h));
        sManager.closeScreen();
        

        sBuild.windowProjection(window);
        sBuild.clearWindow(window);
        sManager.closeRender();

        draw.drawIndetity();

        camera.activate();

        draw.newDraw();
        draw.getInstance(1);
        draw.endDraw();


        draw.newDraw();
        draw.translate(vec3(0.0,0.0,0));
        draw.Rotate(vec4(angulo,1.0,1.0,0.0));
        draw.getInstance(2);
        draw.endDraw();

        angulo += 0.1;

        draw.drawScreen(window);
      }

      sBuild.destroyWindow(window);

      
      return 0;
    }
  }
}


#ifdef CALANGO_PLATFORM_WINDOWS

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
  
  return clg::launcher::calangoMain(0, (char**) lpCmdLine);
}

#else

int main(int argc, char** argv){
    return clg::launcher::calangoMain(argc, argv);
}

#endif  // CALANGO_PLATFORM_WINDOWS