#include <iostream>
#include <fstream>
#include <string>
#include "EstruturaLista.hpp"

using namespace std;

class Buscar
{
private:
    int tam_backspace=0;
    ifstream arquivo;
    Estrutura* palavras = new Estrutura();

public:

    Buscar(){}

    void possiveis_palavras(string palavra)
    {
        int contador=0;
        string temp;

        arquivo.open("banco.txt");

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

    void palavra_predefinida(string palavra)
    {
        string temp;
        tam_backspace=palavra.length();
        arquivo.open("banco.txt");

        while(!arquivo.eof())
        {
            getline(arquivo,temp);

            if(comparar(palavra,temp)==1)
            {
                arquivo.close();
                getPalavra_predefinida(temp);
            }
        }
        arquivo.close();
    }

    //Converte a string codificado do banco.txt em string comum
    void getPalavra_predefinida(string palavra)
    {
        char predef[80];
        bool identificador=false;
        int contador=0;

        for(int x=0; x<palavra.length(); x++)
        {
            if(identificador)
            {
                cout<<(int)palavra[x];
                predef[contador]=palavra[x];
                contador++;
            }

            if(palavra[x]==':')
                identificador=true;
        }
        setPalavras(predef);
    }

    void setPalavras(char* palavra)
    {
        //Apagar o comando passado
        for(int x=0; x<tam_backspace; x++)
        {
            enviarClick(8,0);
        }

        //Caracteres especiais
        for(int x=0; x<strlen(palavra); x++)
        {
            switch((int)palavra[x])
            {
                case 33:
                    enviarClick(49,1);
                    break;

                case 64:
                    enviarClick(50,1);
                    break;

                case 35:
                    enviarClick(51,1);
                    break;

                case 36:
                    enviarClick(52,1);
                    break;

                case 46:
                    enviarClick(190,0);
                    break;

                default:
                    enviarClick((int)palavra[x],0);
                    break;
            }
        }
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

