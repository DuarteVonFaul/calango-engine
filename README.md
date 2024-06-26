# Calango Engine
Este projeto tem como objetivo o desenvolvimento de uma Game Engine do zero utilizando C++, com suporte multiplataforma usando OpenGL e Vulkan. Além disso, a proposta inclui a criação de um jogo do estilo MetroidVania para demonstrar as capacidades da Game Engine.

## 1 Desafio:
Desenvolver uma Game Engine multiplataforma do zero, utilizando OpenLG e Vulkan, e criar um MetroidVania com ela.

## 2 Arquitetura:
A arquitetura pensada terá 3 Soluções:

  - Plataforma onde terá como função padronizar todas as funções OpenGL e Vulkan para multiplataforma
  - Engine que usará as funções da plataforma para gerar funcionalidades próprias para o desenvolvimento de jogos
  - Launcher que será a interface de interação entre o Usuário e a Engine

Todo jogo que for Compilado terá em suas dependências as DLL Plataforma e Engine nas quais serão OBRIGATORIAS para execução do mesmo.

## 3 Dependencias:
  - MinGW
  - GLFW3.x
  - imGUI
  - CMake

## 4 Como usar
Para compilar o projeto, siga os passos abaixo:

    cd src
    CMAKE -G "MinGW Makefiles" -B build .
    cd build
    mingw32-make
    
## 5 Materias de referencia:
Como material de auxilio estou vendo os videos do canal GameDevlog:
[(GameEngineDoZero)](https://www.youtube.com/watch?v=SCL70wik3Ts&list=PLt_f2ildHl1lZdx8R3CjjH50R8EV6d7CH)
Para melhor compreensão e acompanhamento do desenvolvimento da Game Engine, recomenda-se assistir a essa série de vídeos.
Também estou utilizando para estudos os vídeos do canal Sergio Silva que fala sobre Contexto OpenGL [(OpenGL C++ - Gráficos 3D)](https://www.youtube.com/playlist?list=PLVRDPs83ZhmcXYuktF3r2hfyoabg_EVPO)

***Nota1***: Certifique-se de consultar a documentação oficial do CMake para obter informações detalhadas sobre o uso do CMake.

***Nota2***: Caso queriam acompanhar todos os processos do desenvolvimento do projeto temos o [(Trello CalangoEnfine)](https://trello.com/c/Wr7jSJT0/1-informa%C3%A7%C3%B5es-gerais)
