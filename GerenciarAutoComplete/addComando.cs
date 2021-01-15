using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;


namespace GerenciarAutoComplete
{
    class addComando
    {
        public static void adicionarComando(string comando, string resposta)
        {
            string diretorio = "C:\\chrYstYan\\AutoComplete\\db\\";

            if (!Directory.Exists(diretorio))
                Directory.CreateDirectory(diretorio);

            StreamWriter arquivo = File.AppendText(diretorio + "banco.txt");
            string ComUpper = comando.ToUpper();

            string newComando = ComUpper + ":" + resposta;

            arquivo.WriteLine(newComando);
            arquivo.Close();
        }
    }
}
