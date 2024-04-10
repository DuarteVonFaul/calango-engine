#include <calango/calango.hpp>
#include <calango/calango_engine.hpp>
#include <calango/calango_platform.hpp>

namespace clg
{
  namespace launcher
  {

    int calangoMain(int argc, char** argv)
    {

      Scene3D* main = new Scene3D(0);
      
      Engine engine = Engine(main);
      GLFWwindow* window = engine.wManager.createWindow(1280,720,"Game Engine");

      Button* button = new Button(vec2(20.0,20.0),vec2(40.0,40.0),"click");
      main->addControl(button);


      engine.changeScene(main->getId());
      engine.read(window);
      while(!engine.wManager.getWindowCloseFlag(window))
      {
        engine.tick();
      }
      engine.wManager.destroyWindow(window);

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