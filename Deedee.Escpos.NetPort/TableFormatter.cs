using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace Deedee.Escpos.NetPort
{
    public class TableFormatter : IDisposable
    {
        IntPtr ptr;

        public TableFormatter()
        {
            DeedeeTableFormatterCreate(ref ptr);
        }

        public void Dispose()
        {
            DeedeeTableFormatterDestroy(ptr);
        }

        public void DefineColumn(int size)
        {
            DeedeeTableFormatterDefineColumn(ptr, size);
           
        }
        public void AddColumnContent(int idx, Justification justification, string str)
        {
            DeedeeTableFormatterAddColumnContent(ptr, idx, (int)justification, str);
        }
        public void AddRow()
        {
            DeedeeTableFormatterAddRow(ptr);
        }

        internal IntPtr GetHandler()
        {
            return ptr;
        }

        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeTableFormatterCreate(ref IntPtr ptr);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeTableFormatterDestroy(IntPtr ptr);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeTableFormatterDefineColumn(IntPtr ptr, int size);
        [DllImport("Deedee.Escpos.dll", CharSet = CharSet.Unicode)]
        private static extern Int32 DeedeeTableFormatterAddColumnContent(IntPtr ptr, int idx, int justification, string str);
        [DllImport("Deedee.Escpos.dll")]
        private static extern Int32 DeedeeTableFormatterAddRow(IntPtr ptr);


    }
}
