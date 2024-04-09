#include <calango/calango_engine.hpp>
#include <stdio.h>

namespace clg
{
  Engine::Engine(Scene* _root): 
  currentScene(0),
  dManager(DrawManager(1))
  {scenes.push_back(_root);}

  Engine::Engine(std::vector<Scene*> _scenes, FLAGS_ENGINE_SCENE _flagsScene): 
  currentScene(0),
  dManager(DrawManager(1)),
  scenes(_scenes),
  flagsScene(_flagsScene){}

  void Engine::read(GLFWwindow* window)
  {
    this->window->windowContext = window ;
    
    this->wManager.initOpenGL(this->window->windowContext);
    this->window->GuiContext = this->gManager.initOpenGL(this->window->windowContext);

    wManager.clearColorWindow();

    this->scenes[this->currentScene]->read();
    
    if(this->flagsScene.PROJECT_3D){
      this->camera = new clg::Camera2D(clg::vec2(0,0));
    };

    if(this->flagsScene.INITIALIZED_BY_ENGINE){
      this->dManager.orientationPlane(1);
      this->window->viewportPresets = clg::vec4(0.25,0.0,0.5,1.0);
    };





  }

  void Engine::tick()
  {
      this->wManager.updateWindowEvents(this->window->windowContext);
    
      this->wManager.windowProjection(this->window,clg::vec2(this->window->viewportPresets.x,
                                                        this->window->viewportPresets.y)
                                             ,clg::vec2(this->window->viewportPresets.z,
                                                        this->window->viewportPresets.w));
      this->wManager.clearWindow(this->window->windowContext);                                                 
      

      this->dManager.drawIndetity();
      this->camera->activate();
      this->dManager.newDraw();
      this->dManager.getInstance(1);
      this->dManager.endDraw();

      this->scenes[this->currentScene]->tickEntity(&dManager);
      this->gManager.openRender(this->window->GuiContext);
      this->scenes[this->currentScene]->tickControl(&gManager, this->window);
      this->window->OnGui(&gManager);
      this->gManager.closeRender(this->window->GuiContext);
      this->dManager.drawScreen(this->window->windowContext);

  }

  Engine::~Engine(){scenes.~vector();}






}