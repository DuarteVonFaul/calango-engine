#include <calango/calango_platform.hpp>


namespace clg
{
    //
    // Funções inerentes a Criação e Gerenciamento de Janelas
    //
    void clg::ScreenBuilder::showMensage(const char* message){
        MessageBox(0,message,"Calango Engine - Aviso",0);
    };

    clg::ScreenBuilder::ScreenBuilder(){
        /* Aqui eu inicializo o framework glfw */
        if (!glfwInit())
            this->showMensage("Erro ao Inicializar GLFW");
    };
    
    GLFWwindow* clg::ScreenBuilder::createWindow(int width, int height, const char* title){
        /* Aqui eu construo a janela */
        GLFWwindow* window;
        window = glfwCreateWindow(width, height, title, nullptr, nullptr);
        if (!window)
        {
            glfwTerminate();
            return nullptr;
        }
        return window;
    };
    
    void clg::ScreenBuilder::destroyWindow(GLFWwindow* window){
        glfwDestroyWindow(window);
        glfwTerminate();
    };

    bool clg::ScreenBuilder::initOpenGL(GLFWwindow* window){
        /* Aqui eu construo o contexto OpenGL e linko com a tela*/
        glfwMakeContextCurrent(window);
        //glEnable(GL_DEPTH_TEST);
        return true;
    };

    // Função para atualizar eventos da janela GLFW
    void clg::ScreenBuilder::updateWindowEvents(GLFWwindow* window) {
        glfwPollEvents();
        if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
            this->clearWindowCloseFlag(window);
        }
    }

    void clg::ScreenBuilder::clearColorWindow(vec4 clear_color){
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        // glEnable(GL_DEPTH_TEST);
    }

    void clg::ScreenBuilder::windowProjection(GLFWwindow* window)
    {   
        //Aqui eu pego o tamanho da Janela
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        //Aqui eu defino o Viewport da tela ou seja a area de Desenho
        glViewport(width/4, 0, width/2, height);
        float aspect = (float)(width/2)/(float)height;//esse aspect é o controle para manter o aspecto das imagens

        //Antes de eu definir a projeção, eu primeiro defino o tamanho do meu ViewPort
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        
        gluPerspective(45.0, aspect, 0.1, 500);

    }
    
    void clg::ScreenBuilder::clearWindow(GLFWwindow* window){
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    }
    // Função para obter a flag de fechamento da janela GLFW
    bool clg::ScreenBuilder::getWindowCloseFlag(GLFWwindow* window) {
        return glfwWindowShouldClose(window);
    }
    // Função para limpar a flag de fechamento da janela GLFW
    void clg::ScreenBuilder::clearWindowCloseFlag(GLFWwindow* window) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    //
    // Funções inerente a desenhar objetos na tela
    //

    void clg::Draw::newDraw(){
        glPushMatrix();
    }
    
    void clg::Draw::endDraw(){
        glPopMatrix();
    }

    clg::Draw::Draw(int amount){
        this->amount = amount;
        glGenLists(amount);
    }

    void clg::Draw::drawIndetity(){
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    void clg::Draw::translate(clg::vec3 vector){
        glTranslatef(vector.x, vector.y, vector.z);
    }

    void clg::Draw::Rotate(clg::vec4 vector){
        glRotatef(vector.x,vector.y,vector.z,vector.w);
    }

    void clg::Draw::Scale(clg::vec3 vector){
        glScalef(vector.x,vector.y,vector.z);
    }

    void clg::Draw::Triangle(unsigned int id, clg::vec3 p1,clg::vec3 p2,clg::vec3 p3, clg::color color){
        glNewList(id,GL_COMPILE);
            glColor3fv(color);
            glBegin(GL_TRIANGLES);
                glVertex3fv(&p1.x);
                glVertex3fv(&p2.x);
                glVertex3fv(&p3.x);
            glEnd();
        glEndList();
    }

    void clg::Draw::Rect(unsigned int id, clg::vec3 p1,clg::vec3 p2,clg::vec3 p3,clg::vec3 p4, clg::color color){
        glNewList(id,GL_COMPILE);
            glColor3fv(color);
            glBegin(GL_QUADS);
                glVertex3fv(&p1.x);
                glVertex3fv(&p2.x);
                glVertex3fv(&p3.x);
                glVertex3fv(&p4.x);
            glEnd();
        glEndList();
    }

    void clg::Draw::Rect(clg::vec3 p1,clg::vec3 p2,clg::vec3 p3,clg::vec3 p4, clg::color color){
        glColor3fv(color);
        glBegin(GL_QUADS);
            glVertex3fv(&p1.x);
            glVertex3fv(&p2.x);
            glVertex3fv(&p3.x);
            glVertex3fv(&p4.x);
        glEnd();
    }

    void clg::Draw::orientationPlane(unsigned int id, bool _2D ){
        float L = 500.0;
        float y = -0.5;

        
        glNewList(id,GL_COMPILE);
            glColor3fv(clg::WHITE);
            glBegin(GL_LINES);
            if(_2D){
                float incr = 1.5;
                for (float i = -L; i <= L; i += incr)
            {
                glVertex3f(i,-L,-1.0);
                glVertex3f(i,L,-1.0);

                glVertex3f(-L,i,-1.0);
                glVertex3f(L,i,-1.0);
            }
            }else{
            float incr = 1.0;
            for (float i = -L; i <= L; i += incr)
            {
                glVertex3f(i,y,-L);
                glVertex3f(i,y,L);

                glVertex3f(-L,y,i);
                glVertex3f(L,y,i);
            }
            }
            glEnd();
        glEndList();
        
    }

    void clg::Draw::getInstance(int id){
        glCallList(id);
    }

    void clg::Draw::deleteInstace(int id, int interval){
        glDeleteLists(id,interval);
    }

    void clg::Draw::deleteAllInstances(){
        glDeleteLists(1,this->amount);
    }

    void clg::Draw::Cube(unsigned int id, float s){

        float d = s/2.0;

        clg::vec3 v1     = clg::vec3( -d,  d,  d);
        clg::vec3 v2     = clg::vec3( -d, -d,  d);
        clg::vec3 v3     = clg::vec3(  d, -d,  d);
        clg::vec3 v4     = clg::vec3(  d,  d,  d);

        clg::vec3 v5     = clg::vec3(  d,  d, -d);
        clg::vec3 v6     = clg::vec3(  d, -d, -d);
        clg::vec3 v7     = clg::vec3( -d, -d, -d);
        clg::vec3 v8     = clg::vec3( -d,  d, -d);

        glNewList(id,GL_COMPILE);
            glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            this->Rect(v1,v2,v3,v4,clg::RED);
            this->Rect(v4,v3,v6,v5,clg::GREEN);
            this->Rect(v5,v8,v7,v6,clg::VIOLET);
            this->Rect(v1,v8,v7,v2,clg::WHITE);
            this->Rect(v1,v4,v5,v8,clg::GRAY);
            this->Rect(v2,v7,v6,v3,clg::YELLOW);
        glEndList();

    }

    void clg::Draw::Sphere(unsigned int id, GLfloat radius, GLuint nStacks, GLuint nSectores, clg::color color, bool X_RAY_MODE){

        std::vector<std::vector<GLuint>> indices;

        std::vector<clg::vec3> points;

        const GLfloat PI = 3.14159265359;
        GLfloat deltaPhi = PI/nStacks;
        GLfloat deltaTheta = 2*PI/nSectores;

        for (GLuint i=0; i<=nStacks; i++)
        {
            GLfloat phi = -PI /2.0 + i * deltaPhi;
            GLfloat temp = radius * cos(phi);
            GLfloat y = radius * sin(phi);
            std::vector<GLuint> pt;
            for (GLuint j=0; j<nSectores; j++)
            {
                GLfloat theta = j*deltaTheta;
                GLfloat x = temp * sin(theta);
                GLfloat z = temp * cos(theta);

                points.push_back(clg::vec3(x,y,z));
                pt.push_back(points.size() - 1);
            }//next j
            indices.push_back(pt);
        }//next i

        // glColor3fv(clg::RED);
        // glPointSize(2.5);
        // glBegin(GL_POINTS);
        // for (GLuint i = 0; i<points.size(); i++)
        // {
        //     glVertex3fv(&points[i].x);
        // }
        // glEnd();

        
        glNewList(id,GL_COMPILE);
            if(X_RAY_MODE){
                glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
            }   
            glColor3fv(color);
            glEnable(GL_CULL_FACE);
            glFrontFace(GL_CCW);
            glCullFace(GL_BACK);
            for (GLuint i=0; i<nStacks; i++)
            {
                glBegin(GL_TRIANGLE_STRIP);

                for (GLuint j=0; j<nSectores; j++)
                {
                    GLuint index = indices[i][j];
                    glVertex3fv(&points[index].x);
                    index = indices[i+1][j];
                    glVertex3fv(&points[index].x);

                    if(j==nSectores-1){
                    index = indices[i][0];
                    glVertex3fv(&points[index].x);
                    index = indices[i+1][0];
                    glVertex3fv(&points[index].x);
                    }
                }
                glEnd();
            }
            glDisable(GL_CULL_FACE);
        glEndList();
    }

    void clg::Draw::drawScreen(GLFWwindow* window){
        glfwSwapBuffers(window);
    }


    ScreenManager::ScreenManager(){
        #if defined(IMGUI_IMPL_OPENGL_ES2)
            // GL ES 2.0 + GLSL 100
            this->glsl_version = "#version 100";
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
            glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
        #elif defined(__APPLE__)
            // GL 3.2 + GLSL 150
            this->glsl_version = "#version 150";
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
        #else
            // GL 3.0 + GLSL 130
            this->glsl_version = "#version 130";
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
            //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
            //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
        #endif


    };

    void ScreenManager::initOpenGL(GLFWwindow* window){
        IMGUI_CHECKVERSION();
        this->igContext = ImGui::CreateContext();
        this->window = window;
        ImGui::SetCurrentContext(this->igContext);
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls


        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsLight();

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(this->window, true);
        #ifdef __EMSCRIPTEN__
            ImGui_ImplGlfw_InstallEmscriptenCanvasResizeCallback("#canvas");
        #endif
            ImGui_ImplOpenGL3_Init(this->glsl_version.c_str());
    };
    void ScreenManager::openScreen(const char* title, clg::vec2 pos, clg::vec2 size){
        ImGui::SetCurrentContext(this->igContext);
        ImGui::SetNextWindowPos(ImVec2(pos.x,pos.y));

        ImGui::SetNextWindowSize(ImVec2(size.x,size.y));
        ImGui::Begin(title,nullptr);
    };

    void ScreenManager::openScreen(const char* title, float anchor_x,float anchor_y,float size_x,float size_y){
        ImGui::SetCurrentContext(this->igContext);
        int width, height;
        glfwGetFramebufferSize(this->window, &width, &height);
        ImGui::SetNextWindowPos(ImVec2(anchor_x * width,anchor_y * height));
        ImGui::SetNextWindowSize(ImVec2(size_x * width,size_y * height));
        ImGui::Begin(title,nullptr);
    }
    void ScreenManager::closeScreen(){
        ImGui::SetCurrentContext(this->igContext);
        ImGui::End();
    };

    void ScreenManager::openRender(){
        ImGui::SetCurrentContext(this->igContext);
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
    };
    void ScreenManager::closeRender(){
        ImGui::SetCurrentContext(this->igContext);
        ImGui::Render();
        ImGui::EndFrame();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    };


    void ScreenManager::renderButton(clg::vec2 anchor, clg::vec2 size,std::string text,MethodCallback callback)
    {   
        if(ImGui::Button(text.c_str(), ImVec2(size.x, size.y))){
            callback();
        }

    };
    void ScreenManager::renderLabel(clg::vec2 anchor, clg::vec2 size,std::string text,MethodCallback callback)
    {
    };
    void ScreenManager::renderTextArea(clg::vec2 anchor, clg::vec2 size,const char textTitle[100], std::string* textBuffer,MethodCallback callback)
    {   
        char buffer[2048]; // Tamanho adequado para o buffer
        strncpy(buffer, textBuffer->c_str(), sizeof(buffer)); // Copia o conteúdo da string para o buffer
        ImGui::InputTextMultiline(textTitle, buffer, sizeof(buffer), ImVec2(size.x, size.y));
        *textBuffer = buffer;
    };


    
    //
    // Funções inerente a GUI da Tela
    //

}