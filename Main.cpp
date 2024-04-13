#include "Gui.h"
#include <iostream>
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    EmailClient::Gui^ form = gcnew EmailClient::Gui();
    Application::Run(form);

    return 0;
}