#pragma once
#include "../Config.h"
#include "../../model/OutgoingEmailDTO.h"
#include <string>
#include <iostream>
#include <msclr/marshal_cppstd.h>
#include <msclr/marshal.h>
#include <list>
#include <cliext/list>

using System::String;
using System::Collections::Generic::List;
using System::Net::Mail::MailMessage;
using System::Threading::Timer;

namespace EmailClient
{
    public ref class AsyncEmailSender
    {
    public:
        AsyncEmailSender();
        static AsyncEmailSender^ getInstance();
        void AppendEmailQueue(OutgoingMailDTO^ email);

    private:
        void SendEmail(Object^ state);

        List<OutgoingMailDTO^>^ emailsToSend;
        System::Threading::Timer^ timer;
        Config& config;
        static AsyncEmailSender^ instance;
    };
}
