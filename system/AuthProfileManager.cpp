#include "AuthProfileManager.h"

AuthProfilerManager::AuthProfilerManager() : currentProfile(0) {}

AuthProfilerManager^ AuthProfilerManager::getInstance() {
    if (instance == nullptr) {
        instance = gcnew AuthProfilerManager();
    }
    return instance;
}

System::Net::Mail::SmtpClient^ AuthProfilerManager::getSmtpClientByProfileTitle(System::String^ profileTitle) {
    return createSmtpClientByProfile(getProfileByTitle(profileTitle));
}

System::Net::Mail::SmtpClient^ AuthProfilerManager::getSmtpClientByCurrentProfile() {
    return createSmtpClientByProfile(getCurrentProfile());
}

System::Net::Mail::SmtpClient^ AuthProfilerManager::createSmtpClientByProfile(ProfileDTO^ profile) {
    if (profile != nullptr) {
        System::Net::Mail::SmtpClient^ smtpClient = gcnew System::Net::Mail::SmtpClient("smtp-mail.outlook.com", 587);
        smtpClient->Credentials = gcnew System::Net::NetworkCredential(profile->login, profile->password);
        smtpClient->EnableSsl = true;
        return smtpClient;
    }
    return nullptr;
}

ProfileDTO^ AuthProfilerManager::getProfileByTitle(System::String^ title) {
    for each (ProfileDTO ^ profile in profiles) {
        if (profile->title == title) {
            return profile;
        }
    }
    return nullptr;
}

void AuthProfilerManager::setCurrentProfile(int index) {
    if (index >= 0 && index < profiles.size()) {
        currentProfile = index;
    }
}

ProfileDTO^ AuthProfilerManager::getCurrentProfile() {
    if (currentProfile >= 0 && currentProfile < profiles.size()) {
        return profiles[currentProfile];
    }
    return nullptr;
}
