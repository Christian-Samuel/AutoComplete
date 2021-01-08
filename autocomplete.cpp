#include "ApiWindows.hpp"
#include "buscarPalavra.hpp"
#include "novaPalavra.hpp"

int main()
{
    Buscar* teste = new Buscar();

    teste->possiveis_palavras("gos");
    teste->palavras->teste();
    teste->palavras->clearAll();
    teste->possiveis_palavras("sa");
    teste->palavras->teste();

}
