#include "GUI.h"
#include "system/Config.h"
#include <iostream>
#include <Windows.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    System::Windows::Forms::Application::EnableVisualStyles();
    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

    const std::string configFile = "settings.ini";
    Config& config = Config::getInstance();

    if (config.loadConfig(configFile)) {
        std::cout << "config found";
    }
    else {
        config.generateDefaultConfig();
    }

    EmailClient::Gui^ form = gcnew EmailClient::Gui();
    System::Windows::Forms::Application::Run(form);

    return 0;
}