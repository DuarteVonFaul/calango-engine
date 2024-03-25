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
      Draw draw = Draw(1);
      GLFWwindow* window = sBuild.createWindow(1280,720,"GameEngine");
      

      if(! sBuild.initOpenGL(window)){
        // if(!sManager.initOpenGL(window)){
          // return 1;
        // }
        return 1;
      }
      sBuild.clearColorWindow();

      while(!sBuild.getWindowCloseFlag(window))
      {
        sBuild.updateWindowEvents(window);

        // sManager.startRender();
        // sManager.newScreen("TEstando", clg::vec2(0,0), clg::vec2(500,500));
        // sManager.endScreen();
        // sManager.endRender();

        sBuild.windowProjection(window);
        
        sBuild.clearWindow(window);
        draw.drawScreen(window);
      }
      
      sManager.destroyScreen();
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