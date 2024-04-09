#ifndef CALANGO_SCENE
    #define CALANGO_SCENE
    #include <calango/primitives.hpp>
    #include <iostream>

    namespace clg
    {
        class  Scene {

            private:
                int id;
                clg::vec4 presets;
                std::string name;
            public:
                Scene(int _id): id(_id), presets(clg::vec4()){name="New Scene";};
                Scene(int _id, std::string _name): id(_id),name(_name), presets(clg::vec4()){};
                ~Scene();
                virtual void read() const = 0;
                virtual void tickControl() const = 0;
                virtual void tickEntity() const = 0;
        };



        struct FLAGS_ENGINE_SCENE final{
            bool INITIALIZED_BY_ENGINE = true;
            bool PROJECT_3D = true;
            
        };
    }
#endif