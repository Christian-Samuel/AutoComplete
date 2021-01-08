#include <iostream>
#include <fstream>
#include <string>
#include "EstruturaLista.hpp"

using namespace std;

class Buscar
{
private:
    ifstream arquivo;

public:
    Estrutura* palavras = new Estrutura();

    Buscar()
    {

    }

    void possiveis_palavras(string palavra)
    {
        arquivo.open("banco.txt");
        int contador=0;
        string temp;

        while(!arquivo.eof())
        {
            getline(arquivo,temp);

            if(comparar(palavra,temp)==1)
            {
                palavras->add(temp);
                contador++;
            }

        }

        arquivo.close();
    }

    int comparar(string pal1, string pal2)
    {
        int tamanho = pal1.length();

        for(int x=0; x<tamanho; x++)
        {
            if(pal1[x]!=pal2[x])
                return 0;
        }

        return 1;
    }
};

