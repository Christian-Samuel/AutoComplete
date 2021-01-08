
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

    void teste()
    {
        for(int x=posicao; x>=0; x--)
        {
            cout << palavra[x] << "\n";
        }
    }

    void clearAll()
    {
        posicao=0;
        for(int x=0; x<30; x++)
        {
            palavra[x] = "";
        }
    }



};





