#pragma once

namespace EmailClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ProfilesForm
	/// </summary>
	public ref class ProfilesForm : public System::Windows::Forms::Form
	{
	public:
		ProfilesForm(void)
		{
			InitializeComponent();
			LoadProfiles();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProfilesForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ profileGrid;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ TitleColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ EmailColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ LoginColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PasswordColumn;
	private: System::Windows::Forms::Button^ saveProfilesButton;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		System::Void LoadProfiles()
		{
			List<ProfileDTO^>^ profiles = AuthProfileManager::getInstance()->getProfiles();
			for each (ProfileDTO ^ profile in profiles)
			{
				profileGrid->Rows->Add(profile->Title, profile->Email, profile->Login, profile->Password);
			}
		}

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ProfilesForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->saveProfilesButton = (gcnew System::Windows::Forms::Button());
			this->profileGrid = (gcnew System::Windows::Forms::DataGridView());
			this->TitleColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EmailColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LoginColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PasswordColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profileGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->saveProfilesButton);
			this->panel1->Controls->Add(this->profileGrid);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(416, 272);
			this->panel1->TabIndex = 1;
			// 
			// saveProfilesButton
			// 
			this->saveProfilesButton->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->saveProfilesButton->Location = System::Drawing::Point(0, 249);
			this->saveProfilesButton->Name = L"saveProfilesButton";
			this->saveProfilesButton->Size = System::Drawing::Size(416, 23);
			this->saveProfilesButton->TabIndex = 1;
			this->saveProfilesButton->Text = L"Save";
			this->saveProfilesButton->UseVisualStyleBackColor = true;
			this->saveProfilesButton->Click += gcnew System::EventHandler(this, &ProfilesForm::saveProflies);
			// 
			// profileGrid
			// 
			this->profileGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->profileGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->profileGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->TitleColumn,
					this->EmailColumn, this->LoginColumn, this->PasswordColumn
			});
			this->profileGrid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->profileGrid->Location = System::Drawing::Point(0, 0);
			this->profileGrid->Name = L"profileGrid";
			this->profileGrid->Size = System::Drawing::Size(416, 272);
			this->profileGrid->TabIndex = 0;
			// 
			// TitleColumn
			// 
			this->TitleColumn->HeaderText = L"Title";
			this->TitleColumn->Name = L"TitleColumn";
			// 
			// EmailColumn
			// 
			this->EmailColumn->HeaderText = L"Email";
			this->EmailColumn->Name = L"EmailColumn";
			// 
			// LoginColumn
			// 
			this->LoginColumn->HeaderText = L"Login";
			this->LoginColumn->Name = L"LoginColumn";
			// 
			// PasswordColumn
			// 
			this->PasswordColumn->HeaderText = L"Password";
			this->PasswordColumn->Name = L"PasswordColumn";
			// 
			// ProfilesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(416, 272);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ProfilesForm";
			this->Text = L"Profiles";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->profileGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
			private: System::Void saveProflies(System::Object^ sender, System::EventArgs^ e) {
				for each (DataGridViewRow ^ row in profileGrid->Rows) {
					if (row->IsNewRow) continue;

					System::String^ title = safe_cast<System::String^>(row->Cells["TitleColumn"]->Value);
					System::String^ email = safe_cast<System::String^>(row->Cells["EmailColumn"]->Value);
					System::String^ login = safe_cast<System::String^>(row->Cells["LoginColumn"]->Value);
					System::String^ password = safe_cast<System::String^>(row->Cells["PasswordColumn"]->Value);

					ProfileDTO^ profile = gcnew ProfileDTO();
					if (profile != nullptr) {
						profile->Title = title;
						profile->Email = email;
						profile->Login = login;
						profile->Password = password;
					}
					AuthProfileManager::getInstance()->addNewProfileDTO(profile);

				}

				AuthProfileManager::getInstance()->SaveProfilesToFile();
				this->Close();
			}

};
}
