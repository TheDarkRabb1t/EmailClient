#pragma once
#include "ProfileDTO.h"

public ref class OutgoingMailDTO
{
public:
    ProfileDTO^ profile;
    System::Net::Mail::MailMessage^ message;

    OutgoingMailDTO(ProfileDTO^ profile, System::Net::Mail::MailMessage^ message)
        : profile(profile), message(message) {}
};
