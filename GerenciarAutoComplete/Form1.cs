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
using System.Runtime;
using System.Diagnostics;

namespace GerenciarAutoComplete
{
    public partial class Form1 : Form
    {
        ident form = new ident();

        public Form1()
        {
            InitializeComponent();
            //Limpa o historico
            File.Delete("C:\\chrYstYan\\AutoComplete\\db\\interoperabilidade.txt");
            File.Delete("C:\\chrYstYan\\AutoComplete\\db\\palavras_temporarias.txt"); 
        }

        private void label6_Click(object sender, EventArgs e)
        {
            form.Show();
            this.Visible = false;
            notifyIcon1.Visible = true;

        }

        private void notifyIcon1_DoubleClick(object sender, EventArgs e)
        {

            if (!this.Visible)
                this.Visible = true;

            this.WindowState = FormWindowState.Maximized;
            notifyIcon1.Visible = false;

            form.Hide();

        }

        private async void label4_Click(object sender, EventArgs e)
        {
            label4.BackColor = Color.Red;
            await Task.Delay(250);
            label4.BackColor = Color.GreenYellow;
            if (textBox1.Text.Length > 1 && textBox2.Text.Length > 1)
            {
                addComando.adicionarComando(textBox1.Text, textBox2.Text);
                MessageBox.Show("Comando Criado com sucesso!");
                textBox1.Text = "";
                textBox2.Text = "";
            }
            else
            {
                MessageBox.Show("Preencha todos os campos!!");
            }
        }

        private void radioButton2_Click(object sender, EventArgs e)
        {
            foreach (Process process in Process.GetProcessesByName("autocomplete"))
            {
                process.Kill();
                process.WaitForExit();
            }
        }

        private void radioButton1_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("..\\..\\..\\autocomplete.exe");
        }

        private void label7_Click(object sender, EventArgs e)
        {
            foreach (Process process in Process.GetProcessesByName("autocomplete"))
            {
                process.Kill();
                process.WaitForExit();
            }
            Application.Exit();
        }

        private void label4_MouseHover(object sender, EventArgs e)
        {
            Label label = sender as Label;
            label.BackColor = Color.Orange;
        }

        private void label4_MouseLeave(object sender, EventArgs e)
        {
            Label label = sender as Label;
            label.BackColor = Color.GreenYellow;
        }
    }
}
