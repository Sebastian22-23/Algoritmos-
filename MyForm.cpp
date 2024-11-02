#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew GAMEJAM::MyForm());
	//Project1 es el nombre del proyecto
}