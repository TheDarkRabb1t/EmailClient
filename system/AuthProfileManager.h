#pragma once
#include <cliext/vector>
#include "../model/ProfileDto.h"
#include <msclr\marshal_cppstd.h>
#include <msclr\marshal.h>
#include <fstream>
#include <vcclr.h>
#include <vector> // Include vector header for List conversion

using System::Xml::Serialization::XmlSerializer;
using System::IO::FileStream;
using System::IO::File;
using System::IO::FileMode;
using System::Collections::Generic::List; // Include Generic namespace for List

public ref class AuthProfileManager sealed {
public:
    static AuthProfileManager^ getInstance() {
        if (instance == nullptr) {
            instance = gcnew AuthProfileManager();
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
            smtpClient->Credentials = gcnew System::Net::NetworkCredential(profile->Login, profile->Password);
            smtpClient->EnableSsl = true;
            return smtpClient;
        }
        return nullptr;
    }

    ProfileDTO^ getProfileByTitle(System::String^ title) {
        for each (ProfileDTO ^ profile in profiles) {
            if (profile->Title == title) {
                return profile;
            }
        }
        return nullptr;
    }

    List<ProfileDTO^>^ getProfiles() {
        return profiles;
    }

    void SaveProfilesToFile() {
        XmlSerializer^ serializer = gcnew XmlSerializer(profiles->GetType());
        FileStream^ stream = gcnew FileStream(fileName, FileMode::Create);
        serializer->Serialize(stream, profiles);
        stream->Close();
    }

    void LoadProfilesFromFile() {
        XmlSerializer^ serializer = gcnew XmlSerializer(profiles->GetType());
        FileStream^ stream = gcnew FileStream(fileName, FileMode::Open);
        profiles = dynamic_cast<List<ProfileDTO^>^>(serializer->Deserialize(stream));
        stream->Close();
    }

    void setCurrentProfile(int index) {
        if (index >= 0 && index < profiles->Count) {
            currentProfile = index;
        }
    }

    ProfileDTO^ getCurrentProfile() {
        if (currentProfile >= 0 && currentProfile < profiles->Count) {
            return profiles[currentProfile];
        }
        return nullptr;
    }

private:
    AuthProfileManager() : currentProfile(0), fileName("profiles.xml") {
        profiles = gcnew List<ProfileDTO^>();
        if (File::Exists(fileName)) {
            LoadProfilesFromFile();
        }
        else {
            ProfileDTO^ defaultProfile = gcnew ProfileDTO("Outlook", "ctdrtest@outlook.com", "Zxcadmin1");
            profiles->Add(defaultProfile);
            SaveProfilesToFile();
        }
    }

    static AuthProfileManager^ instance;
    List<ProfileDTO^>^ profiles;
    int currentProfile;
    System::String^ const fileName;
};
