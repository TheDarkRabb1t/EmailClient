#pragma once
#include <iostream>
#include "../Config.h"
#include "../../model/OutgoingEmailDTO.h"
#include "../AuthProfileManager.h"
#include <string>

using System::Collections::Generic::List;
using System::Net::Mail::MailMessage;
using System::Net::Mail::SmtpClient;
using System::Threading::TimerCallback;

namespace EmailClient
{
    public ref class AsyncEmailSender
    {
    private:
        List<OutgoingMailDTO^>^ emailsToSend;
        System::Threading::Timer^ timer;
        Config& config = Config::getInstance();

        static AsyncEmailSender^ instance;

        AsyncEmailSender()
        {
            emailsToSend = gcnew List<OutgoingMailDTO^>();
            int emailSendScheduleMilis = stoi(config.getValue("emailSendScheduleMilis"));
            timer = gcnew System::Threading::Timer(gcnew TimerCallback(this, &AsyncEmailSender::SendEmail), nullptr, 0, emailSendScheduleMilis);
        }
    public:
        static AsyncEmailSender^ getInstance()
        {
            if (instance == nullptr)
            {
                instance = gcnew AsyncEmailSender();
            }
            return instance;
        }

        void AppendEmailQueue(OutgoingMailDTO^ email)
        {
            emailsToSend->Add(email);
        }

    private:
        void SendEmail(Object^ state)
        {
            if (emailsToSend->Count > 0)
            {
                OutgoingMailDTO^ oMailDTO = emailsToSend[0];
                emailsToSend->RemoveAt(0);
                
                SmtpClient^ client = AuthProfileManager::getInstance()->getSmtpClientByProfileTitle(oMailDTO->profile->title);
                client->Send(oMailDTO->message);
            }
        }
    };

    public ref class AsyncEmailReceiver
    {
    private:
        List<MailMessage^>^ receivedEmails;
        System::Threading::Timer^ timer;
        Config& config = Config::getInstance();

        static AsyncEmailReceiver^ instance;
        AsyncEmailReceiver()
        {
            receivedEmails = gcnew List<MailMessage^>();
            int emailReceiveScheduleMilis = stoi(config.getValue("emailReceiveScheduleMilis"));
            timer = gcnew System::Threading::Timer(gcnew TimerCallback(this, &AsyncEmailReceiver::ReceiveEmails), nullptr, 0, emailReceiveScheduleMilis);
        }
    public:
        static AsyncEmailReceiver^ getInstance()
        {
            if (instance == nullptr)
            {
                instance = gcnew AsyncEmailReceiver();
            }
            return instance;
        }

        List<MailMessage^>^ GetReceivedEmails()
        {
            return receivedEmails;
        }

    private:
        void ReceiveEmails(Object^ state)
        {
            // Your existing code...
        }
    };
}