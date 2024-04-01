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
      GLFWwindow* window = engine.screenBuilder.createWindow(1280,720,"Game Engine");


      Screen* screen = new Screen(vec2(0.0,0.7),vec2(0.25,0.25),"TESTE");

      main->addControl(screen);


      
      engine.read(window);
      while(!engine.screenBuilder.getWindowCloseFlag(window))
      {
        engine.screenManager.openRender();

          engine.tick();
          engine.screenManager.openScreen("Scene",0.0,0.0,0.25,0.5);
          engine.screenManager.closeScreen();

          engine.screenManager.openScreen("Arquivos",0.0,0.5,0.25,0.5);
          engine.screenManager.closeScreen();

          engine.screenManager.openScreen("Propriedades",0.75,0.0,0.25,1.0);
          engine.screenManager.closeScreen();

        engine.screenManager.closeRender();
        engine.draw.drawScreen(window);
      }
      engine.screenBuilder.destroyWindow(window);

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