/*Classe utilizada para se comunicar com a interface grafica desnvolvida em C#.
A comunicação entre o C++ e o C# é baseada na troca de informações atraves de
arquivos .txt*/

using namespace std;
class CpptoCsharp{

private:
    ifstream arquivoIn[3];
    ofstream arquivoOu[3];
    string patch1 = "C:\\chrYstYan\\AutoComplete\\db\\interoperabilidade.txt";
    string patch2 = "C:\\chrYstYan\\AutoComplete\\db\\palavras_temporarias.txt";
    string patch3 = "C:\\chrYstYan\\AutoComplete\\db\\palavra_final.txt";

public:
    CpptoCsharp(){}

    void setStatus(string status)
    {
        arquivoOu[0].open(patch1);

        arquivoOu[0]<< "status:"<<status;
        arquivoOu[0].close();
    }

    string getPalavra_final()
    {

        string palavra;

        arquivoIn[2].open(patch3);

        getline(arquivoIn[2],palavra);
        arquivoIn[2].close();

        remove(patch3.c_str());

        return palavra;
    }

    void setPalavras(string palavras[],int tamanho)
    {
        arquivoOu[1].open(patch2);

        for(int x=0; x<tamanho; x++)
        {
            arquivoOu[1]<<palavras[x]<<"\n";
        }

        arquivoOu[1].close();
    }

};





