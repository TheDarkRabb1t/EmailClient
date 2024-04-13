#include "GUI.h"
#include "system/Config.h"
#include <iostream>
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    const std::string configFile = "settings.ini";
    Config& config = Config::getInstance();

    if (config.loadConfig(configFile)) {
        std::cout << "config found";
    }
    else {
        config.generateDefaultConfig();
    }

    EmailClient::Gui^ form = gcnew EmailClient::Gui();
    Application::Run(form);

    return 0;
}