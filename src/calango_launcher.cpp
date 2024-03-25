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
      sBuild.showMensage("Testando mensagem");
      
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