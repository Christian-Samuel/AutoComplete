using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace GerenciarAutoComplete
{
    public partial class ident : Form
    {
        string diretorio = "C:\\chrYstYan\\AutoComplete\\db\\interoperabilidade.txt";
        aucom_interface form = new aucom_interface();

        public ident()
        {
            InitializeComponent();
        }

        private void ident_Load(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            try
            {
                StreamReader arquivo = File.OpenText(diretorio);
                string status = arquivo.ReadLine();

                if (status == "status:Desligado")
                {
                    label1.Text = "Desligado";
                    label1.BackColor = Color.Red;
                }

                if (status == "status:Ligado")
                {
                    label1.Text = "Ligado";
                    label1.BackColor = Color.Blue;
                    form.Hide();

                }

                if (status == "status:Lendo")
                {
                    label1.Text = "Lendo..";
                    label1.BackColor = Color.Green;


                    form.Show();
                }

                arquivo.Close();
            }
            catch(System.IO.IOException ex)
            {

            }
        }

        private void label1_Click(object sender, EventArgs e)
        {
            this.Visible = false;
        }
    }
}
