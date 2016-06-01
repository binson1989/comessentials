using System.Runtime.InteropServices;

namespace ManagedApp
{
    class Program
    {
        [DllImport("Library.dll")]
        static extern void Cluck();

        static void Main(string[] args)
        {
            Cluck();
        }
    }
}
