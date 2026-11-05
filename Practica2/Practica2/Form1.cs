using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.Common;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Practica2
{
    public partial class Form1 : Form
    {
        delegate void SetTextDelegate(string value);

        public SerialPort ArduinoPort { get; set; }

        public Form1()
        {
            InitializeComponent();

            ArduinoPort = new System.IO.Ports.SerialPort();
            ArduinoPort.PortName = "COM4"; // Checar en su equipo
            ArduinoPort.BaudRate = 9600;
            ArduinoPort.DataBits = 8;
            ArduinoPort.ReadTimeout = 500;
            ArduinoPort.WriteTimeout = 500;

            ArduinoPort.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);

            // vincular eventos
            this.btnConectar.Click += btnConectar_Click;
            this.btnDesconectar.Click += btnDesconectar_Click;
        }

        private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
        {
            string dato = ArduinoPort.ReadLine();
            EscribirTxt(dato);
        }

        private void EscribirTxt(string dato)
        {
            if (InvokeRequired)
            {
                Invoke(new SetTextDelegate(EscribirTxt), dato);
            }
            else
            {
                try
                {
                    lbTemp.Text = dato;
                }
                catch { }
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void btnConectar_Click(object sender, EventArgs e)
        {
            btnDesconectar.Enabled = true;
            btnConectar.Enabled = false;

            try
            {
                if (!ArduinoPort.IsOpen)
                {
                    ArduinoPort.Open();
                }

                if (int.TryParse(tbLimTemp.Text, out int temperatureLimit))
                {
                    string limitString = temperatureLimit.ToString();
                    ArduinoPort.Write(limitString);
                }
                else
                {
                    MessageBox.Show("Ingresa un valor numérico válido en el TextBox del límite de la temperatura.");
                }

                lbConection.Text = "Conexión OK";
                lbConection.ForeColor = System.Drawing.Color.Lime;
            }
            catch
            {
                MessageBox.Show("Configure el puerto de comunicación correcto o Desconecte");
            }
        }

        private void btnDesconectar_Click(object sender, EventArgs e)
        {
            btnConectar.Enabled = true;
            btnDesconectar.Enabled = false;

            if (ArduinoPort.IsOpen)
            {
                ArduinoPort.Close();
            }

            lbConection.Text = "Desconectado";
            lbConection.ForeColor = System.Drawing.Color.Red;
            lbTemp.Text = "00.0";
        }
    }
}