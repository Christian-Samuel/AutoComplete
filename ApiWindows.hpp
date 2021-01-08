#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <conio.h>
#include "Definicoes_API.hpp"
using namespace std;

//SendInput-->
UINT enviarClick(int letra)
{
    INPUT input[2];

    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = letra;

    input[1].type = INPUT_KEYBOARD;
    input[1].ki.wVk = letra;
    input[1].ki.dwFlags  = KEYEVENTF_KEYUP;

    return (SendInput(2,input,sizeof(INPUT)));
}


//Criar registro SIMPLES
int criarRegistro(HKEY local,LPCSTR chave,string dado)
{
    HKEY identificador;

    if(RegCreateKeyEx(local, chave, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &identificador, NULL)!=ERROR_SUCCESS)
        return 0;


    RegSetValueEx( identificador,NULL,0,REG_SZ,(const BYTE*)dado.c_str(),(dado.size() + 1 ) * sizeof(string));
        return 1;
}









