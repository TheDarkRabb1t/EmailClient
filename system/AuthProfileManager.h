#pragma once
#include <cliext/vector>
#include "../model/ProfileDto.h"

public ref class AuthProfilerManager sealed {
public:
    static AuthProfilerManager^ getInstance() {
        if (instance == nullptr) {
            instance = gcnew AuthProfilerManager();
        }
        return instance;
    }

    System::Net::Mail::SmtpClient^ getSmtpClientByProfileTitle(System::String^ profileTitle) {
        return createSmtpClientByProfile(getProfileByTitle(profileTitle));
    }

    System::Net::Mail::SmtpClient^ getSmtpClientByCurrentProfile() {
        return createSmtpClientByProfile(getCurrentProfile());
    }

    System::Net::Mail::SmtpClient^ createSmtpClientByProfile(ProfileDTO^ profile) {
        if (profile != nullptr) {
            System::Net::Mail::SmtpClient^ smtpClient = gcnew System::Net::Mail::SmtpClient("smtp-mail.outlook.com", 587);
            smtpClient->Credentials = gcnew System::Net::NetworkCredential(profile->login, profile->password);
            smtpClient->EnableSsl = true;
            return smtpClient;
        }
        return nullptr;
    }

    ProfileDTO^ getProfileByTitle(System::String^ title) {
        for each (ProfileDTO ^ profile in profiles) {
            if (profile->title == title) {
                return profile;
            }
        }
        return nullptr;
    }

    void setCurrentProfile(int index) {
        if (index >= 0 && index < profiles.size()) {
            currentProfile = index;
        }
    }

    ProfileDTO^ getCurrentProfile() {
        if (currentProfile >= 0 && currentProfile < profiles.size()) {
            return profiles[currentProfile];
        }
        return nullptr;
    }

private:
    AuthProfilerManager() : currentProfile(0) {}
    static AuthProfilerManager^ instance;
    cliext::vector<ProfileDTO^> profiles;
    int currentProfile;
};