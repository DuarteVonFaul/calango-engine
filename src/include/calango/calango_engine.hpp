#ifndef CALANGO_ENGINE
#define CALANGO_ENGINE

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

        virtual void draw(GuiManager* gui) const = 0 ;

  };


  struct CALANGO_ENGINE_API Engine final
  {
    
    WindowManager wManager;
    GuiManager    gManager;
    DrawManager   dManager;

    Window*       window;
    Camera*       camera;

    int currentScene = 0;
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
  class CALANGO_ENGINE_API Scene2D: public Scene {
    private:
      std::vector<Entity*> entitys;
      std::vector<Control*> controls;
      DrawManager* draw;

    public:
      Scene2D(int _id): Scene(_id){};
      ~Scene2D(){};
      void read() const override{};
      void tickControl(GuiManager* gui, Window* window) const override{};
      void tickEntity() const override{};

  };

  class CALANGO_ENGINE_API Scene3D: public Scene {
    private:
      std::vector<Entity3D*> entitys;
      std::vector<Control*> controls;
      DrawManager* draw;

    public:
      Scene3D(int _id): Scene(_id){};
      ~Scene3D(){};
      void addControl(Control* control) {
        this->controls.push_back(control);
      }
      void read() const override{};
      void tickControl(GuiManager* gui, Window* window) const override;
      void tickEntity() const override;
      

  };


//Classes do grupo Control [GUI]


  class CALANGO_ENGINE_API Box: public Control{
    private:
      std::string name;
      std::vector<Control*> controls;
    public:
      Box(clg::vec2 anchor,clg::vec2 proportion, std::string _name):name(_name), Control(-1,anchor,proportion){};
      void draw(GuiManager* gui) const override{} ;
      void addControl(Control* control){};
  };


  class CALANGO_ENGINE_API Button: public Control{
    private:
      std::string name;
      MethodCallback callback;
    public:
      Button(clg::vec2 anchor,
             clg::vec2 proportion, 
             std::string _name, 
             MethodCallback _callback):
             name(_name), 
             Control(-1,anchor,proportion),
             callback(_callback){};
      Button(clg::vec2 anchor,
             clg::vec2 proportion, 
             std::string _name):
             name(_name), 
             Control(-1,anchor,proportion),
             callback(nullptr){};
      void draw(GuiManager* gui) const override ;
  };


}

#endif  //CALANGO_ENGINE