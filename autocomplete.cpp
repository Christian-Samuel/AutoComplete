#include "ApiWindows.hpp"
#include "buscarPalavra.hpp"
#include "novaPalavra.hpp"

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
        //Sai do Loop geral e volta ao estado inicial
        if(GetAsyncKeyState(VK_F1)==-32767 && GetAsyncKeyState(VK_MENU)==-32767)
        {
            stop=false;
            cout << "Saindo..\n";
            Sleep(500);
        }


        //Entra na captura de teclas
        if(GetAsyncKeyState(VK_F2)==-32767 && GetAsyncKeyState(VK_MENU)==-32767)
        {
            palavra_temp->clearAll();
            Beep(600,250);
            Sleep(500);
            cout << "Aguardando Teclas\n";
            ligado=true;

            while(ligado)
            {
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
                        ligado=false;
                        cout << "Teclas Concluidas\n";
                        Beep(700,250);
                        palavra_temp->exibir();
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
    //Start
    while(1)
    {
        if(GetAsyncKeyState(VK_F1)==-32767  && GetAsyncKeyState(VK_MENU)==-32767)
        {
            Beep(500,300);
            cout << "Ligado\n";
            captura();
        }
    }
}
