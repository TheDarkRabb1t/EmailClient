#include "AsyncEmailReceiver.h"


EmailClient::AsyncEmailReceiver::AsyncEmailReceiver() : config(Config::getInstance())
{
    receivedEmails = gcnew List<MailMessage^>();
    int emailReceiveScheduleMilis = stoi(config.getValue("emailReceiveScheduleMilis"));
    timer = gcnew System::Threading::Timer(gcnew System::Threading::TimerCallback(this, &AsyncEmailReceiver::ReceiveEmails), nullptr, 0, emailReceiveScheduleMilis);
}

EmailClient::AsyncEmailReceiver^ EmailClient::AsyncEmailReceiver::getInstance()
{
    if (instance == nullptr)
    {
        instance = gcnew EmailClient::AsyncEmailReceiver();
    }
    return instance;
}

List<MailMessage^>^ EmailClient::AsyncEmailReceiver::GetReceivedEmails()
{
    return receivedEmails;
}

void EmailClient::AsyncEmailReceiver::ReceiveEmails(Object^ state)
{
    // Your existing code for receiving emails...
}
