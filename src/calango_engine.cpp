#include <calango/calango_engine.hpp>
#include <stdio.h>

namespace clg
{
  Engine::Engine(Scene* _root): 
  currentScene(0), 
  viewportPresets(clg::vec4(0.0,0.0,1.0,1.0)),
  draw(Draw(1)) 
  {scenes.push_back(_root);}

  Engine::Engine(std::vector<Scene*> _scenes, FLAGS_ENGINE_SCENE _flagsScene): 
  currentScene(0),
  viewportPresets(clg::vec4(0.0,0.0,1.0,1.0)),
  draw(Draw(1)),
  scenes(_scenes),
  flagsScene(_flagsScene){}

  void Engine::read(GLFWwindow* window)
  {
    this->window = window ;
    
    this->screenBuilder.initOpenGL(window);
    this->screenManager.initOpenGL(window);

    screenBuilder.clearColorWindow();

    this->scenes[this->currentScene]->read();
    
    if(this->flagsScene.PROJECT_3D){
      this->camera = new clg::Camera2D(clg::vec2(0,0));
    };

    if(this->flagsScene.INITIALIZED_BY_ENGINE){
      this->draw.orientationPlane(1);
      this->viewportPresets = clg::vec4(0.25,0.0,0.5,1.0);
    };





  }

  void Engine::tick()
  {
      this->screenBuilder.updateWindowEvents(window);
    
      this->screenBuilder.windowProjection(window,clg::vec2(this->viewportPresets.x,
                                                        this->viewportPresets.y)
                                             ,clg::vec2(this->viewportPresets.z,
                                                        this->viewportPresets.w));
      this->screenBuilder.clearWindow(this->window);                                                 
      

      this->draw.drawIndetity();
      this->camera->activate();
      this->draw.newDraw();
      this->draw.getInstance(1);
      this->draw.endDraw();

      this->scenes[this->currentScene]->tickEntity();
      this->scenes[this->currentScene]->tickControl(this->viewportPresets, &this->screenManager);

  }

  Engine::~Engine(){scenes.~vector();}






}