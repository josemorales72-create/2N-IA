using System;
using System.IO;
using System.Windows.Forms;

namespace program04
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void btnGuardar_Click(object sender, EventArgs e)
        {
            string nombre = txbNombre.Text.Trim();
            string apellidos = txbApellidos.Text.Trim();
            string telefono = txbTelefono.Text.Trim();
            string edad = txbEdad.Text.Trim();
            string estatura = txbEstatura.Text.Trim();
            string genero = "";

            if (rbFemenino.Checked)
            {
                genero = "Femenino";
            }
            else if (rbMasculino.Checked)
            {
                genero = "Masculino";
            }
            else if (rbOtro.Checked)
            {
                genero = "Otro";
            }

            if (string.IsNullOrEmpty(nombre) || string.IsNullOrEmpty(apellidos) || string.IsNullOrEmpty(genero))
            {
                MessageBox.Show("Por favor completa los campos obligatorios.", "Advertencia", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            string mensaje = $"Nombre: {nombre}\r\nApellidos: {apellidos}\r\nTeléfono: {telefono}\r\nEdad: {edad}\r\nEstatura: {estatura}\r\nGénero: {genero}";
            string rutaArchivo = "datos_registro.txt";

            try
            {
                bool archivoExiste = File.Exists(rutaArchivo);

                using (StreamWriter escritor = new StreamWriter(rutaArchivo, true))
                {
                    if (archivoExiste)
                    {
                        escritor.WriteLine("----------------------------------------");
                    }
                    escritor.WriteLine(mensaje);
                }

                MessageBox.Show(mensaje, "Confirmación de registro", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error al guardar el archivo: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void btnLimpiar_Click(object sender, EventArgs e)
        {
            txbNombre.Clear();
            txbApellidos.Clear();
            txbTelefono.Clear();
            txbEstatura.Clear();
            txbEdad.Clear();
            rbFemenino.Checked = false;
            rbMasculino.Checked = false;
            rbOtro.Checked = false;

            txbNombre.Focus();
        }
    }
}