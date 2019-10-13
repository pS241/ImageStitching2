#include "Main.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]


int main(int argc, char *argv[]) {
	
	do
	{
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);
		Project2::Main nameObjectForm;
		Application::Run(%nameObjectForm);
		cin >> argc;
	} while (argc == 4);
		
		

	
	
	
	
	//return 0;



}
