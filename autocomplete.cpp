#include "ApiWindows.hpp"
#include "buscarPalavra.hpp"
#include <unistd.h>

CpptoCsharp* conectar = new CpptoCsharp();

void auto_complete()
{
    //Dados e estruturas
    EstruturaUn* palavra_temp = new EstruturaUn();
    Buscar* Pesquisa = new Buscar();
    HWND foco;
    ifstream arq;
    int resultado,teclas;
    int contador=0;
    bool ligado=false;

    //Definicoes iniciais
    conectar->setStatus("Lendo");
    palavra_temp->clearAll();
    Sleep(500);
    ligado=true;

    //Loop que captura as teclas
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
                    contador++;

                    //Se 3 ou mais letras foram digitadas, faz uma busca no db para procurar possiveis palavras
                    if(contador>=3)
                        Pesquisa->possiveis_palavras(palavra_temp->getStr());

                    //Salva o foco da janela que esta recebendo as teclas
                    foco = GetForegroundWindow();
                }


                //APAGAR LETRA
                if(GetAsyncKeyState(VK_BACK)==-32767)
                {
                    if(contador>=1)
                    {
                        palavra_temp->pop();
                        contador--;

                        if(contador>=3)
                            Pesquisa->possiveis_palavras(palavra_temp->getStr());
                    }
                    else
                    {
                        remove("C:\\chrYstYan\\AutoComplete\\db\\palavras_temporarias.txt");
                    }

                    foco = GetForegroundWindow();
                }


                //AO CLICAR
                if(GetAsyncKeyState(VK_LBUTTON)<0)
                {
                    Sleep(10);

                    //Testa se o clique gerou uma palavra para ser gerada
                    arq.open("C:\\chrYstYan\\AutoComplete\\db\\palavra_final.txt");
                    if(arq)
                    {
                        arq.close();

                        string palavra=" ";
                        char PREDEF[80];
                        SetForegroundWindow(foco);//Transfere o foco das sugestoes para o campo a ser preenchido
                        Sleep(10);

                        //Requisita a palavra clicada e converte em Char
                        palavra = conectar->getPalavra_final();
                        for(int x=0; x<80; x++)
                        {
                            PREDEF[x]=(char)0;
                        }
                        for(int x=0; x<palavra.length(); x++)
                        {
                            PREDEF[x] = palavra[x];
                        }


                        Pesquisa->tam_backspace = palavra_temp->getTeclas();//Apaga os caracteres digitdos
                        Pesquisa->setPalavras(PREDEF);//Preenche com a palavra selecionada

                        contador=0;
                        palavra_temp->clearAll();
                        remove("C:\\chrYstYan\\AutoComplete\\db\\palavras_temporarias.txt");
                        Sleep(100);
                    }
                }


                //ESPACO
                if(GetAsyncKeyState(VK_SPACE)<0)
                {
                    contador=0;
                    palavra_temp->clearAll();
                    remove("C:\\chrYstYan\\AutoComplete\\db\\palavras_temporarias.txt");
                }
            }


            //Sai da captura de teclas
            if(GetAsyncKeyState(VK_F1)==-32767 && ligado && GetAsyncKeyState(VK_MENU)==-32767)
            {
                conectar->setStatus("Ligado");
                ligado=false;

                Sleep(500);
            }
        }
}

void comandos()
{
    EstruturaUn* palavra_temp = new EstruturaUn();
    Buscar* Pesquisa = new Buscar();
    int resultado,teclas;
    bool ligado=false;

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
                    palavra_temp->add(teclas);


                if(GetAsyncKeyState(VK_BACK)==-32767)
                    palavra_temp->pop();
            }


            //Sai da captura de teclas
            if(GetAsyncKeyState(VK_F2)==-32767 && ligado && GetAsyncKeyState(VK_MENU)==-32767)
            {
                conectar->setStatus("Ligado");
                ligado=false;

                //Chama funcao para executar o comando digitado
                if(palavra_temp->getStr()!="")
                    Pesquisa->palavra_predefinida(palavra_temp->getStr());

                Sleep(500);
            }
        }
}

void captura()
{
    /*Fica em loop até que : 1-F1 seja pressionado e a função autocomplete abre,
     ou 2-F2 seja pressionado e a função comandos abre */
    while(1)
    {
        if(GetAsyncKeyState(VK_F1)==-32767 && GetAsyncKeyState(VK_MENU)==-32767)
        {
            cout<<"\nEntrou";
            auto_complete();
            cout<<"\nSaiu";
        }

        Sleep(1);

        //Entra na captura de teclas
        if(GetAsyncKeyState(VK_F2)==-32767 && GetAsyncKeyState(VK_MENU)==-32767)
        {
            cout<<"\nEntrou";
            comandos();
            cout<<"\nSaiu";
        }
    }
}

int main()
{

//    FreeConsole();//Esconder o console
    conectar->setStatus("Ligado");
    captura();

}
