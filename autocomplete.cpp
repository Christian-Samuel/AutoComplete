#include "ApiWindows.hpp"
#include "buscarPalavra.hpp"
#include "interoperabilidadeCpp.hpp"

CpptoCsharp* conectar = new CpptoCsharp();

void captura()
{
    EstruturaUn* palavra_temp = new EstruturaUn();
    Buscar* Pesquisa = new Buscar();
    int resultado,teclas;
    bool ligado=false;
    bool stop=true;

    /*Fica em loop até que : 1-F1 seja pressionado e a função fecha,
     ou 2-F2 seja pressionado e a captura de teclas se inicia */
    while(stop)
    {
        Sleep(1);

        //Sai do Loop geral e volta ao estado inicial
        if(GetAsyncKeyState(VK_F1)==-32767 && GetAsyncKeyState(VK_MENU)==-32767)
        {
            conectar->setStatus("Desligado");
            stop=false;
            Sleep(500);
        }


        //Entra na captura de teclas
        if(GetAsyncKeyState(VK_F2)==-32767 && GetAsyncKeyState(VK_MENU)==-32767)
        {
            conectar->setStatus("Lendo");
            palavra_temp->clearAll();
            Sleep(500);
            ligado=true;

            while(ligado)
            {
                Sleep(1);

                //Faz a captura das teclas de A a Z
                for(teclas = 65; teclas <= 90; teclas++)
                {
                    resultado = GetAsyncKeyState(teclas);

                    if(resultado == -32767)
                    {
                        palavra_temp->add(teclas);
                    }
                }

                //Sai da captura de teclas
                if(GetAsyncKeyState(VK_F2)==-32767 && ligado && GetAsyncKeyState(VK_MENU)==-32767)
                {
                        conectar->setStatus("Ligado");
                        ligado=false;

                        if(palavra_temp->getStr()!="")
                            Pesquisa->palavra_predefinida(palavra_temp->getStr());

                        Sleep(500);
                }
            }
        }
    }
}

int main()
{

    FreeConsole();//Esconder o console

    conectar->setStatus("Desligado");//Mudar o status no painel de status
    //Start
    while(1)
    {
        if(GetAsyncKeyState(VK_F1)==-32767  && GetAsyncKeyState(VK_MENU)==-32767)
        {
            conectar->setStatus("Ligado");
            captura();
        }
        Sleep(1);
    }
}
