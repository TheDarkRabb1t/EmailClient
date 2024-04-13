#pragma once
#include <cliext/vector>
#include "../model/ProfileDto.h"

public ref class AuthProfilerManager sealed {
public:
    static AuthProfilerManager^ getInstance();
    System::Net::Mail::SmtpClient^ getSmtpClientByProfileTitle(System::String^ profileTitle);
    System::Net::Mail::SmtpClient^ getSmtpClientByCurrentProfile();
    ProfileDTO^ getProfileByTitle(System::String^ title);
    void setCurrentProfile(int index);
    ProfileDTO^ getCurrentProfile();

private:
    AuthProfilerManager();
    System::Net::Mail::SmtpClient^ createSmtpClientByProfile(ProfileDTO^ profile);
    static AuthProfilerManager^ instance;
    cliext::vector<ProfileDTO^> profiles;
    int currentProfile;
};
