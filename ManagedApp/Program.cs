using System;
using System.Runtime.InteropServices;

namespace ManagedApp
{
    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    [Guid("e03ac9b2-ccf6-40a8-b122-e6ab51cace3b")]
    interface IHen
    {
        [PreserveSig] void Cluck();
        [PreserveSig] void Roost();
    }

    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    [Guid("0480272e-713e-422b-ae48-2f31e10ef8d7")]
    interface IHen2
    {
        //IHen
        [PreserveSig] void Cluck();
        [PreserveSig] void Roost();

        //IHen2
        [PreserveSig] void Forage();
    }

    [InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    [Guid("231f3bfe-b771-47ae-8619-b6c8a032fa43")]
    interface IOfflineChicken
    {

    }

    class Program
    {
        [DllImport("Library.dll", PreserveSig = false)]
        static extern IHen CreateHen();

        static void Main(string[] args)
        {
            IHen hen = CreateHen();
            hen.Cluck();
            hen.Roost();

            IHen2 hen2 = (IHen2)hen;
            hen2.Forage();
        }
    }
}
