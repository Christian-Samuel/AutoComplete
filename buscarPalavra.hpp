#include <iostream>
#include <fstream>
#include <string>
#include "EstruturaLista.hpp"
#include "interoperabilidadeCpp.hpp"


using namespace std;

class Buscar
{
private:
    ifstream arquivo;
    Estrutura* palavras = new Estrutura();
    CpptoCsharp* requisicoes = new CpptoCsharp();

public:
    int tam_backspace=0;
    Buscar(){}

    //Verifica se as letras digitadas correspondem a alguma palavra salva no banco de dados
    void possiveis_palavras(string palavra)
    {
        int contador=0;
        string temp;
        palavras->clearAll();

        arquivo.open("C:\\chrYstYan\\AutoComplete\\db\\database.txt");

        while(!arquivo.eof())
        {
            getline(arquivo,temp);

           //Armazena em uma estrutura as possiveis palavras
            if(comparar(palavra,temp)==1)
            {
                palavras->add(temp);
                contador++;
            }
        }
        arquivo.close();

        //Gera um .txt com as possiveis palavras que devem ser lidas e mostradas na interface C#
        requisicoes->setPalavras(palavras->getString(),palavras->getPos());
    }


    /*Recebe um comando do usuario e verifica no
      banco de dados se ele existe*/
    int palavra_predefinida(string palavra)
    {
        string temp;

        tam_backspace=palavra.length();
        arquivo.open("C:\\chrYstYan\\AutoComplete\\db\\banco.txt");
            cout<<palavra<<"\n";


        while(!arquivo.eof())//Varre o arquivo em busca do comando solicitado
        {
            getline(arquivo,temp);
            if(ver_comando(palavra,temp)==1)
            {
                cout<<temp<<"\n";
                arquivo.close();
                getPalavra_predefinida(temp);
                return 1;
            }
        }
        arquivo.close();
        return 0;
    }

    //Converte a string codificado do banco.txt em string comum
    void getPalavra_predefinida(string palavra)
    {
        char predef[80];
        bool identificador=false;
        int contador=0;

        for(int x=0; x<palavra.length(); x++)
        {

            if(identificador)//Quando o identificador e encontrado, comeca o processo de transcricao da resposta
            {
                predef[contador]=palavra[x];
                contador++;
            }

            //Neste ponto ele encontrou o marcador que delimita o comando da resposta
            if(palavra[x]==':')
                identificador=true;
        }
        setPalavras(predef);
    }

    void setPalavras(char palavra[])
    {
        Sleep(500);

            //Apagar o comando digitado pelo usuario
            for(int x=0; x<tam_backspace; x++)
            {
                enviarClick(8,0);
            }


        //Impressao de caracteres
        for(int x=0; x<strlen(palavra); x++)
        {
            if((int)palavra[x]>=97 && (int)palavra[x]<=122)//Verifica se a letra e maiuscula ou minuscula
            {
                enviarClick((int)palavra[x]-32,0);
            }
            else
            {
                //Em todos os casos se verifica a existencia de algum caractere especial
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

                    default://Este caso considera um caractere comum
                        enviarClick((int)palavra[x],1);
                        break;
                }
            }
        }
    }

    /*Comparar 2 strings
    1-proto-Palavra digitada pelo usuario
    2-palavra do banco de dados*/
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

    /**/
    int ver_comando(string pal1, string pal2)
    {
        char identificador;
        int x=0;

        while(identificador!=':')
        {
            identificador=pal2[x];

            if(identificador==':')
            {

            }
            else
            {
                if(pal1[x]!=pal2[x])
                    return 0;
            }

            x++;
        }
        return 1;
    }
};

