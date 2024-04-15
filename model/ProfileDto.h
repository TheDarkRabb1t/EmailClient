#pragma once
public ref class ProfileDTO
{
public:
    // Public properties
    property System::String^ Title {
        System::String^ get() { return title; }
        void set(System::String^ value) { title = value; }
    }

    property System::String^ Email {
        System::String^ get() { return email; }
        void set(System::String^ value) { email = value; }
    }

    property System::String^ Login {
        System::String^ get() { return login; }
        void set(System::String^ value) { login = value; }
    }

    property System::String^ Password {
        System::String^ get() { return password; }
        void set(System::String^ value) { password = value; }
    }

    // Parameterized constructor with email equal to login
    ProfileDTO(System::String^ title, System::String^ email, System::String^ password)
        : title(title), email(email), login(email), password(password) {}

    // Parameterized constructor with different email and login
    ProfileDTO(System::String^ title, System::String^ email, System::String^ login, System::String^ password)
        : title(title), email(email), login(login), password(password) {}

    // Parameterless constructor (added to support serialization)
    ProfileDTO() {}

    // Method to get MailAddress
    System::Net::Mail::MailAddress^ GetMailAddress() {
        return gcnew System::Net::Mail::MailAddress(email);
    }
    void SetMailAddress(System::Net::Mail::MailAddress^ mailAddress) {
        email = mailAddress->Address;
    }

private:
    // Private fields
    System::String^ title;
    System::String^ email;
    System::String^ login;
    System::String^ password;
};
