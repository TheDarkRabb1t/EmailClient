#pragma once
#include "../Config.h"
#include <string>
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
#include <list>
#include <cliext/list>
#include <cliext/vector>

using System::String;
using System::Collections::Generic::List;
using System::Net::Mail::MailMessage;
using System::Threading::Timer;

namespace EmailClient
{
    public ref class AsyncEmailReceiver
    {
    public:
        AsyncEmailReceiver();
        static AsyncEmailReceiver^ getInstance();
        List<MailMessage^>^ GetReceivedEmails();

    private:
        void ReceiveEmails(Object^ state);

        List<MailMessage^>^ receivedEmails;
        Timer^ timer;
        Config& config;
        static AsyncEmailReceiver^ instance;
    };
}
