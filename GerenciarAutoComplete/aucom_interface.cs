using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GerenciarAutoComplete
{
    public partial class aucom_interface : Form
    {
        interfaceControle controle = new interfaceControle();

        public aucom_interface()
        {
            InitializeComponent();
        }

        private void aucom_interface_Load(object sender, EventArgs e)
        {
            Label[] objeto = {label1,label2,label3, label4, label5, label6, label7, label8, label9, label10, label11, label12
            , label13, label14, label15, label16, label17, label18, label19, label20, label21, label22, label23, label24, label25
            , label26, label27, label28};
            controle.inicializar(objeto);
            timer1.Enabled = true;

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            controle.setPalavras();
        }

        private void label1_Click(object sender, EventArgs e)
        {
            Label palavra = sender as Label;
            controle.sendPalavra(palavra);
        }
    }
}
