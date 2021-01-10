using namespace std;

class CpptoCsharp{
private:
    ifstream arquivoIn;
    ofstream arquivoOu;
    string patch = "C:\\chrYstYan\\AutoComplete\\db\\interoperabilidade.txt";

public:
    CpptoCsharp(){}

    void setStatus(string status)
    {
        arquivoOu.open(patch);

        arquivoOu<< "status:"<<status;
        arquivoOu.close();
    };

    //string getStatus(){};

};





