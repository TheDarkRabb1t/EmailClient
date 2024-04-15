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
using System::Exception;
using System::Console;

using EAGetMail::Mail;
using EAGetMail::MailInfo;
using EAGetMail::ServerProtocol;
using EAGetMail::MailServer;
using EAGetMail::MailClient;


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
                
                SmtpClient^ client = AuthProfileManager::getInstance()->getSmtpClientByProfileTitle(oMailDTO->profile->Title);
                client->Send(oMailDTO->message);
            }
        }
    };

    public ref class AsyncEmailReceiver
    {
    private:
        List<Mail^>^ receivedEmails;
        System::Threading::Timer^ timer;
        Config& config = Config::getInstance();

        static AsyncEmailReceiver^ instance;
        AsyncEmailReceiver()
        {
            receivedEmails = gcnew List<Mail^>();
            int emailReceiveScheduleMilis = stoi(config.getValue("emailReceiveScheduleMilis"));
            timer = gcnew System::Threading::Timer(gcnew TimerCallback(this, &AsyncEmailReceiver::RetrieveEmails), nullptr, 0, emailReceiveScheduleMilis);
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

        List<Mail^>^ GetReceivedEmails()
        {
            return receivedEmails;
        }

    private:
        void RetrieveEmails(Object^ state)
        {
            ProfileDTO^ currentProfile = AuthProfileManager::getInstance()->getCurrentProfile();
            MailServer^ oServer = gcnew MailServer("outlook.office365.com", currentProfile->Email, currentProfile->Password, ServerProtocol::Imap4);
            MailClient^ oClient = gcnew MailClient("TryIt");
            oServer->SSLConnection = true;
            oServer->Port = 993;

            try {
                oClient->Connect(oServer);
                array<EAGetMail::MailInfo^>^ mailInfos = oClient->GetMailInfos();
                for (int i = 0; i < 10 && i < mailInfos->Length; i++)
                {
                    MailInfo^ info = dynamic_cast<MailInfo^>(mailInfos->GetValue(i));
                    Mail^ oMail = oClient->GetMail(info);
                    receivedEmails->Add(oMail);
                }
            }
            catch (Exception^ ep)
            {
                Console::WriteLine("Error: {0}", ep->Message);
            }
        }

    };
}