#include "ApiWindows.hpp"
#include "buscarPalavra.hpp"
#include "novaPalavra.hpp"

void captura()
{
    EstruturaUn* palavra_temp = new EstruturaUn();
    int resultado,teclas;
    bool ligado=false;
    bool stop=true;

    /*Fica em loop até que : 1-F2 seja pressionado e a função fecha,
     ou 2-F3 seja pressionado e a captura de teclas se inicia */
    while(stop)
    {
        //Sai do Loop geral e volta ao estado inicial
        if(GetAsyncKeyState(VK_F2)!=0)
        {
            stop=false;
            cout << "Saindo..\n";
            Sleep(500);
        }


        //Entra na captura de teclas
        if(GetAsyncKeyState(VK_F3)!=0)
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
                    Sleep(1);
                    resultado = GetAsyncKeyState(teclas);

                    if(resultado == -32767)
                    {
                        palavra_temp->add(teclas);
                    }
                }

                if(GetAsyncKeyState(VK_F3)!=0 && ligado)
                {
                        ligado=false;
                        cout << "Teclas Concluidas\n";
                        Beep(700,250);
                        palavra_temp->exibir();
                        Sleep(500);
                }

            }
        }
    }
}
int main()
{
    Buscar* teste = new Buscar();

    //Start
    while(1)
    {
        if(GetAsyncKeyState(VK_F2)!=0)
        {
            Beep(500,300);
            cout << "Ligado\n";
            captura();
        }
    }

    /*teste->possiveis_palavras("gos");
    teste->palavras->teste();
    teste->palavras->clearAll();
    teste->possiveis_palavras("sa");
    teste->palavras->teste();*/

}
