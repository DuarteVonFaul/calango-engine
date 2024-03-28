#include <calango/calango.hpp>
#include <calango/calango_engine.hpp>
#include <calango/calango_platform.hpp>

namespace clg
{
  namespace launcher
  {

    std::string bTexte = "cliqueAqui";
    std::string BufferText = "";
    void alterText(){
      bTexte = BufferText;
    };

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
      draw.Cube(2,5.0);
      draw.orientationPlane(1);
      clg::Camera2D camera = clg::Camera2D(clg::vec2(0,0));
      
      float angulo = 0.0;
      while(!sBuild.getWindowCloseFlag(window))
      {
        sBuild.updateWindowEvents(window);

        sManager.openRender();
        sManager.openScreen("Scene",0.0,0.0,0.25,0.5);
        sManager.closeScreen();
        sManager.openScreen("Arquivos",0.0,0.5,0.25,0.5);
        sManager.renderTextArea(clg::vec2(),clg::vec2(200.0,100.0),"TextoTeste", &BufferText,alterText);
        sManager.closeScreen();
        sManager.openScreen("Propriedade",0.75,0.0,0.25,1);
        sManager.renderButton(clg::vec2(),clg::vec2(100.0,30.0),bTexte,alterText);
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

        angulo += 0.25;

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