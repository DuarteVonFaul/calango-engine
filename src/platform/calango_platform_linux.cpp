#include <calango/calango_platform.hpp>
#include <cstddef>
#include <cstdio>

namespace clg
{

    void Platform::showMensage(const char* message){
        char text[500];
        snprintf(text, sizeof(text), "zenity --warning \
            --title 'Confirm to Proceed' \
            --width 500 --height 100 \
            --text '%s'", message);

        FILE* fp=popen(text, "r");
        if (fp==NULL) {
        perror("Pipe returned a error");
        } else {
        printf("Exit code: %i\n",WEXITSTATUS(pclose(fp)));
        } 
    }

    Platform::Platform(){
        /* Aqui eu inicializo o framework glfw */
        if (!glfwInit())
            this->showMensage("Erro ao Inicializar GLFW");
    };
    GLFWwindow* Platform::createWindow(int width, int height, const char* title){
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


    void Platform::destroyWindow(GLFWwindow* window){
        glfwDestroyWindow(window);
        glfwTerminate();
    };

    bool Platform::initOpenGL(GLFWwindow* window){
        /* Aqui eu construo o contexto OpenGL e linko com a tela*/
        glfwMakeContextCurrent(window);
        glEnable(GL_DEPTH_TEST);
        return true;
    };

    // Função para atualizar eventos da janela GLFW
    void Platform::updateWindowEvents(GLFWwindow* window) {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // Função para obter a flag de fechamento da janela GLFW
    bool Platform::getWindowCloseFlag(GLFWwindow* window) {
        return glfwWindowShouldClose(window);
    }

    // Função para limpar a flag de fechamento da janela GLFW
    void Platform::clearWindowCloseFlag(GLFWwindow* window) {
        glfwSetWindowShouldClose(window, GLFW_FALSE);
    }

}