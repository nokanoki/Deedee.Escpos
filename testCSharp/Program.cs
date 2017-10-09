using Deedee.Escpos.NetPort;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace testCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            var printer = new Printer("POS-80");
            using (var doc = new EscposDocument())
            {
                doc.Reset();

                doc.Write("test");
                doc.Feed();

                doc.SetJustification(Justification.Center);
                doc.WriteBarcode(BarcodeType.CODE39, "12345678901");
                doc.Write("12345678901");
                doc.Feed(3);

                doc.WriteQR_OEM(OEMCorrectionLevel.H, 8, "http:://www.google.gr");
                doc.Feed();

                doc.SetPrintMode(Font.FontA, true, true, true);
                doc.SetJustification(Justification.Center);
                doc.SetCodePage(737);
                doc.SetPrinterCodePage(64);
                doc.Write("ΠΑΟ-ΟΣΦΜ");
                doc.Feed();

                doc.SetPrintMode(Font.FontA, false, false, false);
                doc.SetJustification(Justification.Right);
                doc.Write("right text");
                doc.Feed();
                doc.Cut(1);

                printer.Print(doc);
                
                
                
            }
        }
    }
}
