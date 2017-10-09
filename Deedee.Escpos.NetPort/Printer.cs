using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Deedee.Escpos.NetPort
{
    public class Printer
    {
        private string printerName;
        public Printer(string printerName)
        {
            this.printerName = printerName;
        }
        public void Print(EscposDocument doc)
        {
            var res = DeedeePrint(printerName, doc.GetHandler());
            Console.WriteLine(res);
        }
        [DllImport("Deedee.Escpos.dll", CharSet = CharSet.Unicode)]
        private static extern Int32 DeedeePrint(string printerName, IntPtr doc);
    }
}
