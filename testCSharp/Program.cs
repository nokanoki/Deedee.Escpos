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
                doc.SetJustification(Justification.Left);


                using (var table = new TableFormatter())
                {
                    var testProduct = new string[]
                    {
                        "milk", "coffee", "sugar","oats","beer","water"
                    };
                    Random rnd = new Random();

                    table.DefineColumn(5);
                    table.DefineColumn(15);
                    table.DefineColumn(20);

                    for (int i = 0; i < 10; i++)
                    {
                        var column0 = rnd.Next(1, 9).ToString() + "x";
                        var column1 = testProduct[rnd.Next(0, testProduct.Length)];
                        var column2 = rnd.Next(0, 20).ToString() + "." + rnd.Next(10, 99).ToString();

                        table.AddColumnContent(0, Justification.Left, column0);
                        table.AddColumnContent(1, Justification.Left, column1);
                        table.AddColumnContent(2, Justification.Right, column2);
                        table.AddRow();
                    }

                    doc.WriteTableFormatter(table);
                }
                doc.Feed(4);
                doc.Cut(1);




                printer.Print(doc);



            }
        }
    }
}
