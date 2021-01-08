
using namespace std;

class Estrutura {
private:
    string palavra[30];
    int posicao;



public:

//Construtor
    Estrutura()
    {
        posicao=0;
    }


//Metodos
    void add(string new_palavra)
    {
        palavra[posicao] = new_palavra;
        posicao++;
    }

    void clearAll()
    {
        posicao=0;
        for(int x=0; x<30; x++)
        {
            palavra[x] = "";
        }
    }

    void teste()
    {
        for(int x=posicao; x>=0; x--)
        {
            cout << palavra[x] << "\n";
        }
    }



};

class EstruturaUn
{
private:
    int PalavraNum[30];
    string PalavraChar;
    char palavra[30];
    int posicao;

public:
    EstruturaUn()
    {
        posicao=0;
    }

    void add(int num)
    {
        PalavraNum[posicao]=num;
        palavra[posicao]=num;
        PalavraChar = palavra;
        posicao++;
    }

    int getNum(int pos)
    {
        return PalavraNum[pos];
    }

    string getStr()
    {
        return PalavraChar;
    }

    void exibir()
    {
        cout << PalavraChar;
    }

    void clearAll()
    {
        PalavraChar="";
        for(int x=0; x<30; x++)
        {
            palavra[x]=(char)0;
        }
        posicao=0;
    }

};



