#pragma once

#include "system/AuthProfileManager.h";
#include "model/ProfileDto.h";

namespace EmailClient {

    using namespace System;
    using namespace System::Windows::Forms;

    public ref class ProfilesForm : public System::Windows::Forms::Form
    {
    public:
        ProfilesForm()
        {
            InitializeComponent();
            LoadProfiles();
        }

    protected:
        ~ProfilesForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::ComboBox^ comboBoxProfiles;
        System::Windows::Forms::Label^ labelTitle;
        System::Windows::Forms::TextBox^ textBoxTitle;
        System::Windows::Forms::Label^ labelEmail;
        System::Windows::Forms::TextBox^ textBoxEmail;
        System::Windows::Forms::Label^ labelLogin;
        System::Windows::Forms::TextBox^ textBoxLogin;
        System::Windows::Forms::Label^ labelPassword;
        System::Windows::Forms::TextBox^ textBoxPassword;
        System::Windows::Forms::Button^ btnSave;

        void InitializeComponent(void)
        {
            this->components = gcnew System::ComponentModel::Container();
            this->comboBoxProfiles = gcnew System::Windows::Forms::ComboBox();
            this->labelTitle = gcnew System::Windows::Forms::Label();
            this->textBoxTitle = gcnew System::Windows::Forms::TextBox();
            this->labelEmail = gcnew System::Windows::Forms::Label();
            this->textBoxEmail = gcnew System::Windows::Forms::TextBox();
            this->labelLogin = gcnew System::Windows::Forms::Label();
            this->textBoxLogin = gcnew System::Windows::Forms::TextBox();
            this->labelPassword = gcnew System::Windows::Forms::Label();
            this->textBoxPassword = gcnew System::Windows::Forms::TextBox();
            this->btnSave = gcnew System::Windows::Forms::Button();
            this->SuspendLayout();

            // comboBoxProfiles
            this->comboBoxProfiles->Location = System::Drawing::Point(12, 12);
            this->comboBoxProfiles->Size = System::Drawing::Size(200, 21);
            this->comboBoxProfiles->DropDownStyle = ComboBoxStyle::DropDownList;
            this->comboBoxProfiles->SelectedIndexChanged += gcnew System::EventHandler(this, &ProfilesForm::comboBoxProfiles_SelectedIndexChanged);

            // labelTitle
            this->labelTitle->Location = System::Drawing::Point(12, 50);
            this->labelTitle->Text = L"Title:";
            // textBoxTitle
            this->textBoxTitle->Location = System::Drawing::Point(100, 50);
            this->textBoxTitle->Size = System::Drawing::Size(200, 20);

            // labelEmail
            this->labelEmail->Location = System::Drawing::Point(12, 80);
            this->labelEmail->Text = L"Email:";
            // textBoxEmail
            this->textBoxEmail->Location = System::Drawing::Point(100, 80);
            this->textBoxEmail->Size = System::Drawing::Size(200, 20);

            // labelLogin
            this->labelLogin->Location = System::Drawing::Point(12, 110);
            this->labelLogin->Text = L"Login:";
            // textBoxLogin
            this->textBoxLogin->Location = System::Drawing::Point(100, 110);
            this->textBoxLogin->Size = System::Drawing::Size(200, 20);

            // labelPassword
            this->labelPassword->Location = System::Drawing::Point(12, 140);
            this->labelPassword->Text = L"Password:";
            // textBoxPassword
            this->textBoxPassword->Location = System::Drawing::Point(100, 140);
            this->textBoxPassword->Size = System::Drawing::Size(200, 20);
            this->textBoxPassword->PasswordChar = '*';

            // btnSave
            this->btnSave->Location = System::Drawing::Point(100, 180);
            this->btnSave->Size = System::Drawing::Size(75, 23);
            this->btnSave->Text = L"Save";
            this->btnSave->Click += gcnew System::EventHandler(this, &ProfilesForm::btnSave_Click);

            // ManageProfilesForm
            this->ClientSize = System::Drawing::Size(320, 240);
            this->Controls->Add(this->comboBoxProfiles);
            this->Controls->Add(this->labelTitle);
            this->Controls->Add(this->textBoxTitle);
            this->Controls->Add(this->labelEmail);
            this->Controls->Add(this->textBoxEmail);
            this->Controls->Add(this->labelLogin);
            this->Controls->Add(this->textBoxLogin);
            this->Controls->Add(this->labelPassword);
            this->Controls->Add(this->textBoxPassword);
            this->Controls->Add(this->btnSave);
            this->Text = L"Manage Profiles";
            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void LoadProfiles()
        {
            AuthProfileManager^ profileManager = AuthProfileManager::getInstance();
            List<ProfileDTO^>^ profiles = profileManager->getProfiles();
            for each (ProfileDTO ^ profile in profiles)
            {
                comboBoxProfiles->Items->Add(profile->Title);
            }
        }

        void comboBoxProfiles_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
        {
            AuthProfileManager^ profileManager = AuthProfileManager::getInstance();
            ProfileDTO^ selectedProfile = profileManager->getProfileByTitle(comboBoxProfiles->Text);
            if (selectedProfile != nullptr)
            {
                textBoxTitle->Text = selectedProfile->Title;
                //textBoxEmail->Text = selectedProfile->email->Address;
                textBoxLogin->Text = selectedProfile->Login;
                textBoxPassword->Text = selectedProfile->Password;
            }
        }

        void btnSave_Click(System::Object^ sender, System::EventArgs^ e)
        {
            AuthProfileManager^ profileManager = AuthProfileManager::getInstance();
            ProfileDTO^ selectedProfile = profileManager->getProfileByTitle(comboBoxProfiles->Text);
            if (selectedProfile != nullptr)
            {
                selectedProfile->Title = textBoxTitle->Text;
                //selectedProfile->Email = gcnew System::Net::Mail::MailAddress(textBoxEmail->Text);
                selectedProfile->Login = textBoxLogin->Text;
                selectedProfile->Password = textBoxPassword->Text;
                profileManager->SaveProfilesToFile();
                MessageBox::Show("Profile saved successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }
    };
}
