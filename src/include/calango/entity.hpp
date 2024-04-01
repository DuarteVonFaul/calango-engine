#ifndef CALANGO_ENTITY
    #define CALANGO_ENTITY
    #include <calango/primitives.hpp>

    namespace clg
    {
        class  Entity {

            private:
                int id;
            public:
                Entity(int _id): id(_id){};
                ~Entity();
        };

        class Entity2D: public Entity{

            private:
                clg::vec2 pos;
                clg::vec2 size;
                float     rotate;
                float     scale;

            public:
                virtual void draw() const = 0 ;

                virtual void setPos()  const = 0 ;
                virtual clg::vec2 getPos()  const = 0 ;

                virtual void setSize()  const = 0 ;
                virtual clg::vec2 getSize()  const = 0 ;

                virtual void setScale()  const = 0 ;
                virtual int getScale()  const = 0 ;

      };

        class Entity3D: public Entity{

            private:
                clg::vec3 pos;
                clg::vec3 size;
                clg::vec4 rotate;
                float       scale;

            public:
                virtual void draw()  const = 0 ;

                virtual void setPos()  const = 0 ;
                virtual clg::vec3 getPos() const = 0 ;

                virtual void setRotate() const = 0 ;
                virtual clg::vec4 getRotate() const = 0 ;

                virtual void setScale() const = 0 ;
                virtual float getScale() const = 0 ;

      };
    }
#endif