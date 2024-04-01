#ifndef CALANGO_ENGINE
#define CALANGO_ENGINE

#include <calango/calango_platform.hpp>
#include <calango/primitives.hpp>
#include <calango/scene.hpp>
#include <calango/entity.hpp>
#include <vector>

#ifdef CALANGO_PLATFORM_WINDOWS
#ifdef CALANGO_ENGINE_IMPLEMENTATION
#define CALANGO_ENGINE_API __declspec(dllexport)
#else
#define CALANGO_ENGINE_API __declspec(dllimport)
#endif //CALANGO_ENGINE_IMPLEMENTATION
#else
#define CALANGO_ENGINE_API
#endif // CALANGO_PLATFORM_WINDOWS

namespace clg
{

  class Control{
    public:
        int id;
        clg::vec2 anchor;
        clg::vec2 proportion;
    public:
        Control(int _id, clg::vec2 _anchor, clg::vec2 _proportion): 
        anchor(_anchor),
        proportion(_proportion),
        id(_id){};

        virtual void draw(clg::vec4 viewportPresets, ScreenManager* screenManager) const = 0 ;

  };


  struct CALANGO_ENGINE_API Engine final
  {
    ScreenBuilder screenBuilder;
    ScreenManager screenManager;
    Draw          draw;
    clg::vec4     viewportPresets;

    GLFWwindow* window;
    Camera*     camera;

    int currentScene;
    std::vector<Scene*> scenes;
    FLAGS_ENGINE_SCENE flagsScene;

    Engine(Scene* root);
    Engine(std::vector<Scene*> _scenes, FLAGS_ENGINE_SCENE _flagsScene);
    ~Engine();

    void addScene(){};
    void changeScene(int targetScene){};
    void read(GLFWwindow* window);
    void tick();


  };


//Classes para Cenas
  class Scene2D: public Scene {
    private:
      std::vector<Entity*> entitys;
      std::vector<Control*> controls;
    public:

      Scene2D(int _id): Scene(_id){};
      ~Scene2D(){};
      void read() const override{};
      void tickControl(clg::vec4 viewportPresets, ScreenManager* screenManager) const override{};
      void tickEntity() const override{};

  };

  class Scene3D: public Scene {
    private:
      std::vector<Entity3D*> entitys;
      std::vector<Control*> controls;
    public:
      Scene3D(int _id): Scene(_id){};
      ~Scene3D(){};
      void addControl(Control* control) {
        this->controls.push_back(control);
      }
      void read() const override{};
      void tickControl(clg::vec4 viewportPresets, ScreenManager* screenManager) const override
      {
        for(Control* control : this->controls){
            control->draw(viewportPresets, screenManager);
        };
      };
      void tickEntity() const override{};
      

  };


//Classes do grupo Control [GUI]


  class Screen: public Control{
    private:
      std::string name;
      std::vector<Control*> controls;
    public:
      Screen(clg::vec2 anchor,clg::vec2 proportion, std::string _name):name(_name), Control(-1,anchor,proportion){};
      void draw(clg::vec4 viewportPresets, ScreenManager* screenManager) const override{
        screenManager->openScreen(this->name.c_str(), 
                                (this->anchor.x+viewportPresets.x),
                                (this->anchor.y+viewportPresets.y),
                                (this->proportion.x*viewportPresets.z),
                                (this->proportion.y*viewportPresets.w));
        screenManager->closeScreen();
      } ;
      void addControl(Control* control){};
  };

}

#endif  //CALANGO_ENGINE