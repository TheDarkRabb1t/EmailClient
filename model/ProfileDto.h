#pragma once

public ref class ProfileDTO
{
public:
    System::String^ title;
    System::Net::Mail::MailAddress^ email;
    System::String^ login;
    System::String^ password;

    // email==login
    ProfileDTO(System::String^ title, System::String^ email, System::String^ password)
        : title(title), email(gcnew System::Net::Mail::MailAddress(email)), login(email), password(password) {}

    // email!=login
    ProfileDTO(System::String^ title, System::String^ email, System::String^ login, System::String^ password)
        : title(title), email(gcnew System::Net::Mail::MailAddress(email)), login(login), password(password) {}
};
