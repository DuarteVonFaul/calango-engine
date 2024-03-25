#include <calango/calango_engine.hpp>
#include <stdio.h>

namespace clg
{
  Engine::Engine()
  {
    printf("engine strted\n");
  }

  Engine::~Engine()
  {
    printf("engine terminated\n");
  }
}