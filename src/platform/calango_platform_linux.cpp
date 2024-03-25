#include <calango/calango_platform.hpp>
#include <cstddef>
#include <cstdio>

namespace clg
{

    void ScreenBuilder::showMensage(const char* message){
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

}