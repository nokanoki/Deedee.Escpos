using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Deedee.Escpos.NetPort
{
    public class EscposDocument : IDisposable
    {
        private IntPtr ptr;
        public EscposDocument()
        {
            DeedeeDocCreate(ref ptr);
        }
        public void Dispose()
        {
            DeedeeDocDestroy(ptr);
        }
        internal IntPtr GetHandler()
        {
            return ptr;
        }




        public void Write(string s)
        {
            DeedeeDocWrite(ptr, s);
        }
        public void Feed()
        {
            DeedeeDocFeed(ptr);
        }
        public void Feed(int lines)
        {
            DeedeeDocFeedLines(ptr, lines);
        }
        public void Cut(int cutType)
        {
            DeedeeDocCut(ptr, cutType);
        }
        public void ReverseFeed(int lines)
        {
            DeedeeDocReverseFeed(ptr, lines);
        }
        /*
            IMPORTAN!! Check printers selfprint for codepage mapping
        */
        public void SetPrinterCodePage(int codePage)
        {
            DeedeeDocSetPrinterCodePage(ptr, codePage);
        }
        public void SetCodePage(int codePage)
        {
            DeedeeDocSetCodePage(ptr, codePage);
        }
        public void SetJustification(Justification justification)
        {
            DeedeeDocSetJustificationMode(ptr, (int)justification);
        }
        public void SetUnderline(IntPtr ptr, Underline underline)
        {
            DeedeeDocSetUnderlineMode(ptr, (int)underline);
        }
        public void SetBold(bool enable)
        {
            DeedeeDocSetEmphasized(ptr, enable ? 1 : 0);
        }
        public void SetFont(Font font)
        {
            DeedeeDocSetFont(ptr, (int)font);
        }
        public void Reset()
        {
            DeedeeDocReset(ptr);
        }
        public void SetDoubleStrike(bool enable)
        {
            DeedeeDocSetDoubleStrike(ptr, enable ? 1 : 0);
        }
        public void SetPrintMode(Font font, bool bold,bool doubleHeight,bool doubleWitdh)
        {
            DeedeeDocPrintMode(ptr, (int)font,
                bold ? 1 : 0,
                doubleHeight ? 1 : 0,
                doubleWitdh ? 1 : 0

                );
        }
        public void WriteBarcode(BarcodeType type,string s)
        {
            DeedeeDocWriteBarcode(ptr, (int)type, s);
        }
        public void WriteQR(QRType type,CorrectionLevel correction, string s)
        {
            DeedeeDocWriteQR(ptr, (int)type, (int)correction, s);
        }
        public void WriteQR_OEM(OEMCorrectionLevel correction, int magnification, string s)
        {
            DeedeeDocWriteQR1(ptr, magnification, (int)correction, s);
        }
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocCreate(ref IntPtr ptr);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocDestroy(IntPtr ptr);
        [DllImport("Deedee.Escpos.dll", CharSet = CharSet.Unicode)]
        private static extern Int32 DeedeeDocWrite(IntPtr ptr, string s);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocFeedLines(IntPtr ptr, int lines);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocFeed(IntPtr ptr);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocCut(IntPtr ptr, int cutType);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocReverseFeed(IntPtr ptr, int lines);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocSetPrinterCodePage(IntPtr ptr, int codePage);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocSetCodePage(IntPtr ptr, int codePage);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocSetJustificationMode(IntPtr ptr, int mode);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocSetUnderlineMode(IntPtr ptr, int mode);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocSetEmphasized(IntPtr ptr, int mode);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocSetFont(IntPtr ptr, int font);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocReset(IntPtr ptr);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocSetDoubleStrike(IntPtr ptr, int enable);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeDocPrintMode(IntPtr ptr, int font, int bold, int doubleHeight, int doubleWidth);
        [DllImport("Deedee.Escpos.dll", CharSet = CharSet.Unicode)]
        private static extern Int32 DeedeeDocWriteBarcode(IntPtr ptr, int model, string s);
        [DllImport("Deedee.Escpos.dll", CharSet = CharSet.Unicode)]
        private static extern Int32 DeedeeDocWriteQR(IntPtr ptr, int model, int correction, string s);
        [DllImport("Deedee.Escpos.dll", CharSet = CharSet.Unicode)]
        private static extern Int32 DeedeeDocWriteQR1(IntPtr ptr, int magnification, int correction, string s);

    }
}
