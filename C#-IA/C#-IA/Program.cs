using System;

namespace EstructuraDatos
{
    class Program
    {
        // Función para leer un tamaño válido de arreglo
        static int LeerDimension()
        {
            int n;
            do
            {
                Console.Write("Ingrese la cantidad de elementos (N > 0): ");
            } while (!int.TryParse(Console.ReadLine(), out n) || n <= 0);
            return n;
        }
        // Procedimiento para la captura de datos
        static void CapturarArreglo(int[] arreglo, int n)
        {
            for (int i = 0; i < n; i++)
            {
                Console.Write($"Ingrese el entero para la posición [{i}]: ");
                while (!int.TryParse(Console.ReadLine(), out arreglo[i]))
                {
                    Console.Write($"Entrada inválida. Reintente posición [{i}]: ");
                }
            }
        }
        // Función para calcular la sumatoria
        static int CalcularSumatoria(int[] arreglo, int n)
        {
            int total = 0;
            for (int i = 0; i < n; i++)
            {
                total += arreglo[i];
            }
            return total;
        }

        // Procedimiento para mostrar el arreglo
        static void MostrarArreglo(int[] arreglo, int n)
        {
            Console.WriteLine("\n--- Elementos del Arreglo ---");
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine($"Índice [{i}] = {arreglo[i]}");
            }
        }

        static void Main(string[] args)
        {
            int n = LeerDimension();
            int[] vector = new int[n];

            CapturarArreglo(vector, n);
            MostrarArreglo(vector, n);

            int sumaTotal = CalcularSumatoria(vector, n);
            Console.WriteLine($"\nSumatoria total de elementos: {sumaTotal}");

            Console.WriteLine("\nPresione cualquier tecla para salir...");
            Console.ReadKey();
        }
    }
}