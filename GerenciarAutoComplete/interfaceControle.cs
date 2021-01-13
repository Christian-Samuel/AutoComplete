using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Windows.Forms;


namespace GerenciarAutoComplete
{
    class interfaceControle
    {
        //Dados
        private Label[] itens = new Label[28];
        public int posicao = 0;
        string diretorioEntrada = "C:\\chrYstYan\\AutoComplete\\db\\palavras_temporarias.txt";
        string diretorioSaida = "C:\\chrYstYan\\AutoComplete\\db\\palavra_final.txt";

        //Construtor
        public interfaceControle()
        {

        }

        //Inicializa o controle com as labels que mostrarão as palavras
        public void inicializar(Label[] labels)
        {
            for (int x = 0; x < 28; x++)
            {
                this.itens[x] = labels[x];
            }
        }

        //Metodos
        //Adiciona uma palavra a interface
        public void add(string nome)
        {

            this.itens[posicao].Text = nome;
            this.itens[posicao].Visible = true;
            
            this.posicao += 1;

        }


        //Limpa a tela
        public void clear()
        {
            for (int x = 0; x < 28; x++)
            {
                this.itens[x].Text = "";
                this.itens[x].Visible = false;
            }
            this.posicao = 0;
        }


        //Ao ser clicado, gera um .txt com a palavra selecionada que sera interpretado pelo script em C
        public void sendPalavra(Label palavra)
        {
            string palavraMin = palavra.Text.ToLower();
            try
            {
                File.WriteAllText(diretorioSaida, palavraMin);
            }
            catch(System.IO.IOException ex)
            {

            }
        }

        //Exibe todas as palavras que estão no arquivo .txt gerado pelo script em C
        public void setPalavras()
        {
            clear();
            try
            {
                StreamReader arquivo = File.OpenText(diretorioEntrada);
                while (!arquivo.EndOfStream)
                {
                    add(arquivo.ReadLine());
                }
                arquivo.Close();
            }
            catch (System.IO.IOException ex)
            {
                
            }
            

            
        }
    }
}
