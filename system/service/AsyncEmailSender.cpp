#include "AsyncEmailSender.h"

EmailClient::AsyncEmailSender::AsyncEmailSender() : config(Config::getInstance())
{
    emailsToSend = gcnew List<OutgoingMailDTO^>();
    int emailSendScheduleMilis = stoi(config.getValue("emailSendScheduleMilis"));
    timer = gcnew System::Threading::Timer(gcnew System::Threading::TimerCallback(this, &AsyncEmailSender::SendEmail), nullptr, 0, emailSendScheduleMilis);
}

EmailClient::AsyncEmailSender^ EmailClient::AsyncEmailSender::getInstance()
{
    if (instance == nullptr)
    {
        instance = gcnew EmailClient::AsyncEmailSender();
    }
    return instance;
}

void EmailClient::AsyncEmailSender::AppendEmailQueue(OutgoingMailDTO^ email)
{
    emailsToSend->Add(email);
}

void EmailClient::AsyncEmailSender::SendEmail(Object^ state)
{
    if (emailsToSend->Count > 0)
    {
        OutgoingMailDTO^ email = emailsToSend[0];
        emailsToSend->RemoveAt(0);
        // Send the email...
    }
}
