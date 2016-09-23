using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace TemplateApp
{
    public partial class DxControl : UserControl
    {
        bool initialized=false;
        bool enablePaint;
        public double angle = 0;
        public bool EnablePaint
        {
            get { return enablePaint; }
            set { 
                enablePaint = value;  
                if(enablePaint)
                {
                    if (!initialized)
                    {
                        DllImportFunctions.InitDirectX((int)Handle);
                        DllImportFunctions.PrepareScene((int)Handle, Width, Height);
                        initialized = true;
                    }
                }
                }
        }
        public DxControl()
        {
            InitializeComponent();
        }
        protected override void OnPaintBackground(PaintEventArgs pevent) { }

        private void DxControl_Paint(object sender, PaintEventArgs e)
        {
            if(initialized)  DllImportFunctions.RenderScene((int)Handle, angle);
        }

        private void DxControl_SizeChanged(object sender, EventArgs e)
        {
            if (initialized) EnablePaint = true;
            Invalidate();
        }        

    }
}
public class DllImportFunctions
{
    [DllImport("DirectXCppCode.Dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "InitDirectX")]
    public static extern void InitDirectX(int hwnd);

    [DllImport("DirectXCppCode.Dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "PrepareScene")]
    public static extern void PrepareScene(int hdc, int w, int h);

    [DllImport("DirectXCppCode.Dll", CallingConvention = CallingConvention.Cdecl, EntryPoint = "RenderScene")]
    public static extern void RenderScene(int hdc, double angle);

}
