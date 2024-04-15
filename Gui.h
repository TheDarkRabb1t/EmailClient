#pragma once
#include "NewLetterForm.h"
#include "SettingsForm.h"
#include "AboutWindow.h"
#include "ProfilesForm.h"
#include "system/AuthProfileManager.h"
#include "model/ProfileDto.h"

namespace EmailClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Gui
	/// </summary>
	public ref class Gui : public System::Windows::Forms::Form
	{
	public:
		Gui(void)
		{
			InitializeComponent();
			updateProfileBox();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Gui()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ headerBodySplitContainer;
	private: System::Windows::Forms::GroupBox^ systemButtons;
	private: System::Windows::Forms::Button^ saveButton;

	private: System::Windows::Forms::Button^ settingsButton;

	private: System::Windows::Forms::Button^ infoButton;

	private: System::Windows::Forms::SplitContainer^ menuLettersSplitContainer;
	private: System::Windows::Forms::SplitContainer^ searchLetterListSplitContainer;

	private: System::Windows::Forms::GroupBox^ itemsMenu;






	private: System::Windows::Forms::Button^ sentButton;

	private: System::Windows::Forms::Button^ incomingButton;
	private: System::Windows::Forms::ListView^ letterList;
	private: System::Windows::Forms::Button^ spamButton;
	private: System::Windows::Forms::Button^ draftedButton;

	private: System::Windows::Forms::RichTextBox^ searchTextField;

	private: System::Windows::Forms::Button^ createNewMail;
	private: System::Windows::Forms::ComboBox^ currentProfileBox;
	private: System::ComponentModel::IContainer^ components;






	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Gui::typeid));
			this->headerBodySplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->systemButtons = (gcnew System::Windows::Forms::GroupBox());
			this->currentProfileBox = (gcnew System::Windows::Forms::ComboBox());
			this->infoButton = (gcnew System::Windows::Forms::Button());
			this->settingsButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->menuLettersSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->itemsMenu = (gcnew System::Windows::Forms::GroupBox());
			this->spamButton = (gcnew System::Windows::Forms::Button());
			this->draftedButton = (gcnew System::Windows::Forms::Button());
			this->sentButton = (gcnew System::Windows::Forms::Button());
			this->incomingButton = (gcnew System::Windows::Forms::Button());
			this->searchLetterListSplitContainer = (gcnew System::Windows::Forms::SplitContainer());
			this->searchTextField = (gcnew System::Windows::Forms::RichTextBox());
			this->createNewMail = (gcnew System::Windows::Forms::Button());
			this->letterList = (gcnew System::Windows::Forms::ListView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->headerBodySplitContainer))->BeginInit();
			this->headerBodySplitContainer->Panel1->SuspendLayout();
			this->headerBodySplitContainer->Panel2->SuspendLayout();
			this->headerBodySplitContainer->SuspendLayout();
			this->systemButtons->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->menuLettersSplitContainer))->BeginInit();
			this->menuLettersSplitContainer->Panel1->SuspendLayout();
			this->menuLettersSplitContainer->Panel2->SuspendLayout();
			this->menuLettersSplitContainer->SuspendLayout();
			this->itemsMenu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->searchLetterListSplitContainer))->BeginInit();
			this->searchLetterListSplitContainer->Panel1->SuspendLayout();
			this->searchLetterListSplitContainer->Panel2->SuspendLayout();
			this->searchLetterListSplitContainer->SuspendLayout();
			this->SuspendLayout();
			// 
			// headerBodySplitContainer
			// 
			this->headerBodySplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->headerBodySplitContainer->Location = System::Drawing::Point(0, 0);
			this->headerBodySplitContainer->Name = L"headerBodySplitContainer";
			this->headerBodySplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// headerBodySplitContainer.Panel1
			// 
			this->headerBodySplitContainer->Panel1->Controls->Add(this->systemButtons);
			this->headerBodySplitContainer->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Gui::splitContainer1_Panel1_Paint_1);
			this->headerBodySplitContainer->Panel1MinSize = 50;
			// 
			// headerBodySplitContainer.Panel2
			// 
			this->headerBodySplitContainer->Panel2->Controls->Add(this->menuLettersSplitContainer);
			this->headerBodySplitContainer->Panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Gui::splitContainer1_Panel2_Paint_1);
			this->headerBodySplitContainer->Panel2MinSize = 250;
			this->headerBodySplitContainer->Size = System::Drawing::Size(1078, 558);
			this->headerBodySplitContainer->SplitterDistance = 59;
			this->headerBodySplitContainer->TabIndex = 0;
			// 
			// systemButtons
			// 
			this->systemButtons->Controls->Add(this->currentProfileBox);
			this->systemButtons->Controls->Add(this->infoButton);
			this->systemButtons->Controls->Add(this->settingsButton);
			this->systemButtons->Controls->Add(this->saveButton);
			this->systemButtons->Dock = System::Windows::Forms::DockStyle::Fill;
			this->systemButtons->Location = System::Drawing::Point(0, 0);
			this->systemButtons->MaximumSize = System::Drawing::Size(0, 50);
			this->systemButtons->MinimumSize = System::Drawing::Size(0, 50);
			this->systemButtons->Name = L"systemButtons";
			this->systemButtons->Size = System::Drawing::Size(1078, 50);
			this->systemButtons->TabIndex = 0;
			this->systemButtons->TabStop = false;
			this->systemButtons->Text = L"System";
			this->systemButtons->Enter += gcnew System::EventHandler(this, &Gui::systemButtons_Enter);
			// 
			// currentProfileBox
			// 
			this->currentProfileBox->Dock = System::Windows::Forms::DockStyle::Right;
			this->currentProfileBox->FormattingEnabled = true;
			this->currentProfileBox->Location = System::Drawing::Point(936, 16);
			this->currentProfileBox->Name = L"currentProfileBox";
			this->currentProfileBox->Size = System::Drawing::Size(139, 21);
			this->currentProfileBox->TabIndex = 3;
			this->currentProfileBox->Text = L"Current Profile";
			this->currentProfileBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Gui::selectedProfileChanged);
			// 
			// infoButton
			// 
			this->infoButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->infoButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"infoButton.Image")));
			this->infoButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->infoButton->Location = System::Drawing::Point(153, 16);
			this->infoButton->Name = L"infoButton";
			this->infoButton->Size = System::Drawing::Size(75, 31);
			this->infoButton->TabIndex = 2;
			this->infoButton->Text = L"about";
			this->infoButton->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->infoButton->UseVisualStyleBackColor = true;
			this->infoButton->Click += gcnew System::EventHandler(this, &Gui::openAboutWindow);
			// 
			// settingsButton
			// 
			this->settingsButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->settingsButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"settingsButton.Image")));
			this->settingsButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->settingsButton->Location = System::Drawing::Point(78, 16);
			this->settingsButton->Name = L"settingsButton";
			this->settingsButton->Size = System::Drawing::Size(75, 31);
			this->settingsButton->TabIndex = 1;
			this->settingsButton->Text = L"settings";
			this->settingsButton->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->settingsButton->UseVisualStyleBackColor = true;
			this->settingsButton->Click += gcnew System::EventHandler(this, &Gui::openSettingsForm);
			// 
			// saveButton
			// 
			this->saveButton->Dock = System::Windows::Forms::DockStyle::Left;
			this->saveButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveButton.Image")));
			this->saveButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->saveButton->Location = System::Drawing::Point(3, 16);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(75, 31);
			this->saveButton->TabIndex = 0;
			this->saveButton->Text = L"profiles";
			this->saveButton->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &Gui::openProfilesWindow);
			// 
			// menuLettersSplitContainer
			// 
			this->menuLettersSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->menuLettersSplitContainer->Location = System::Drawing::Point(0, 0);
			this->menuLettersSplitContainer->Name = L"menuLettersSplitContainer";
			// 
			// menuLettersSplitContainer.Panel1
			// 
			this->menuLettersSplitContainer->Panel1->Controls->Add(this->itemsMenu);
			this->menuLettersSplitContainer->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Gui::splitContainer1_Panel1_Paint_2);
			// 
			// menuLettersSplitContainer.Panel2
			// 
			this->menuLettersSplitContainer->Panel2->Controls->Add(this->searchLetterListSplitContainer);
			this->menuLettersSplitContainer->Size = System::Drawing::Size(1078, 495);
			this->menuLettersSplitContainer->SplitterDistance = 359;
			this->menuLettersSplitContainer->TabIndex = 0;
			// 
			// itemsMenu
			// 
			this->itemsMenu->Controls->Add(this->spamButton);
			this->itemsMenu->Controls->Add(this->draftedButton);
			this->itemsMenu->Controls->Add(this->sentButton);
			this->itemsMenu->Controls->Add(this->incomingButton);
			this->itemsMenu->Dock = System::Windows::Forms::DockStyle::Fill;
			this->itemsMenu->Location = System::Drawing::Point(0, 0);
			this->itemsMenu->MinimumSize = System::Drawing::Size(0, 504);
			this->itemsMenu->Name = L"itemsMenu";
			this->itemsMenu->Size = System::Drawing::Size(359, 504);
			this->itemsMenu->TabIndex = 0;
			this->itemsMenu->TabStop = false;
			this->itemsMenu->Text = L"Mail Types";
			// 
			// spamButton
			// 
			this->spamButton->Dock = System::Windows::Forms::DockStyle::Top;
			this->spamButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"spamButton.Image")));
			this->spamButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->spamButton->Location = System::Drawing::Point(3, 112);
			this->spamButton->Name = L"spamButton";
			this->spamButton->Size = System::Drawing::Size(353, 32);
			this->spamButton->TabIndex = 3;
			this->spamButton->Text = L"Spam";
			this->spamButton->UseVisualStyleBackColor = true;
			// 
			// draftedButton
			// 
			this->draftedButton->Dock = System::Windows::Forms::DockStyle::Top;
			this->draftedButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"draftedButton.Image")));
			this->draftedButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->draftedButton->Location = System::Drawing::Point(3, 80);
			this->draftedButton->Name = L"draftedButton";
			this->draftedButton->Size = System::Drawing::Size(353, 32);
			this->draftedButton->TabIndex = 2;
			this->draftedButton->Text = L"Drafted";
			this->draftedButton->UseVisualStyleBackColor = true;
			// 
			// sentButton
			// 
			this->sentButton->Dock = System::Windows::Forms::DockStyle::Top;
			this->sentButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sentButton.Image")));
			this->sentButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->sentButton->Location = System::Drawing::Point(3, 48);
			this->sentButton->Name = L"sentButton";
			this->sentButton->Size = System::Drawing::Size(353, 32);
			this->sentButton->TabIndex = 1;
			this->sentButton->Text = L"Sent";
			this->sentButton->UseVisualStyleBackColor = true;
			// 
			// incomingButton
			// 
			this->incomingButton->BackColor = System::Drawing::SystemColors::Control;
			this->incomingButton->Dock = System::Windows::Forms::DockStyle::Top;
			this->incomingButton->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"incomingButton.Image")));
			this->incomingButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->incomingButton->Location = System::Drawing::Point(3, 16);
			this->incomingButton->Name = L"incomingButton";
			this->incomingButton->Size = System::Drawing::Size(353, 32);
			this->incomingButton->TabIndex = 0;
			this->incomingButton->Text = L"Incoming";
			this->incomingButton->UseVisualStyleBackColor = false;
			// 
			// searchLetterListSplitContainer
			// 
			this->searchLetterListSplitContainer->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->searchLetterListSplitContainer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->searchLetterListSplitContainer->FixedPanel = System::Windows::Forms::FixedPanel::Panel1;
			this->searchLetterListSplitContainer->Location = System::Drawing::Point(0, 0);
			this->searchLetterListSplitContainer->Name = L"searchLetterListSplitContainer";
			this->searchLetterListSplitContainer->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// searchLetterListSplitContainer.Panel1
			// 
			this->searchLetterListSplitContainer->Panel1->Controls->Add(this->searchTextField);
			// 
			// searchLetterListSplitContainer.Panel2
			// 
			this->searchLetterListSplitContainer->Panel2->Controls->Add(this->createNewMail);
			this->searchLetterListSplitContainer->Panel2->Controls->Add(this->letterList);
			this->searchLetterListSplitContainer->Panel2MinSize = 50;
			this->searchLetterListSplitContainer->Size = System::Drawing::Size(715, 495);
			this->searchLetterListSplitContainer->SplitterDistance = 25;
			this->searchLetterListSplitContainer->TabIndex = 0;
			// 
			// searchTextField
			// 
			this->searchTextField->Dock = System::Windows::Forms::DockStyle::Fill;
			this->searchTextField->Location = System::Drawing::Point(0, 0);
			this->searchTextField->Name = L"searchTextField";
			this->searchTextField->Size = System::Drawing::Size(711, 21);
			this->searchTextField->TabIndex = 0;
			this->searchTextField->Text = L"";
			// 
			// createNewMail
			// 
			this->createNewMail->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->createNewMail->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"createNewMail.Image")));
			this->createNewMail->Location = System::Drawing::Point(652, 409);
			this->createNewMail->Margin = System::Windows::Forms::Padding(3, 3, 10, 10);
			this->createNewMail->Name = L"createNewMail";
			this->createNewMail->Size = System::Drawing::Size(49, 42);
			this->createNewMail->TabIndex = 4;
			this->createNewMail->UseVisualStyleBackColor = true;
			this->createNewMail->Click += gcnew System::EventHandler(this, &Gui::openNewLetterForm);
			// 
			// letterList
			// 
			this->letterList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->letterList->GridLines = true;
			this->letterList->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->letterList->HideSelection = false;
			this->letterList->Location = System::Drawing::Point(0, 0);
			this->letterList->Name = L"letterList";
			this->letterList->Size = System::Drawing::Size(711, 462);
			this->letterList->TabIndex = 0;
			this->letterList->UseCompatibleStateImageBehavior = false;
			this->letterList->View = System::Windows::Forms::View::List;
			this->letterList->SelectedIndexChanged += gcnew System::EventHandler(this, &Gui::listBox1_SelectedIndexChanged);
			// 
			// Gui
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1078, 558);
			this->Controls->Add(this->headerBodySplitContainer);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MinimumSize = System::Drawing::Size(540, 350);
			this->Name = L"Gui";
			this->Text = L"Email Client";
			this->Load += gcnew System::EventHandler(this, &Gui::GUI_Load);
			this->headerBodySplitContainer->Panel1->ResumeLayout(false);
			this->headerBodySplitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->headerBodySplitContainer))->EndInit();
			this->headerBodySplitContainer->ResumeLayout(false);
			this->systemButtons->ResumeLayout(false);
			this->menuLettersSplitContainer->Panel1->ResumeLayout(false);
			this->menuLettersSplitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->menuLettersSplitContainer))->EndInit();
			this->menuLettersSplitContainer->ResumeLayout(false);
			this->itemsMenu->ResumeLayout(false);
			this->searchLetterListSplitContainer->Panel1->ResumeLayout(false);
			this->searchLetterListSplitContainer->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->searchLetterListSplitContainer))->EndInit();
			this->searchLetterListSplitContainer->ResumeLayout(false);
			this->ResumeLayout(false);

		}


#pragma endregion
	private: System::Void splitContainer1_Panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void splitContainer1_Panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void splitContainer1_Panel2_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void splitContainer1_Panel1_Paint_1(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void splitContainer1_Panel1_Paint_2(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void GUI_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	}


	private: System::Void trashCanButton_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void openNewLetterForm(System::Object^ sender, System::EventArgs^ e) {
		EmailClient::NewLetterForm^ newLetterForm = gcnew EmailClient::NewLetterForm();
		newLetterForm->Show();
	}
	private: System::Void openSettingsForm(System::Object^ sender, System::EventArgs^ e) {
		EmailClient::SettingsForm^ settingsForm = gcnew EmailClient::SettingsForm();
		settingsForm->Show();
	}
	private: System::Void openAboutWindow(System::Object^ sender, System::EventArgs^ e) {
		EmailClient::AboutWindow^ aboutWindow = gcnew EmailClient::AboutWindow();
		aboutWindow->Show();
	}
	private: System::Void systemButtons_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void openProfilesWindow(System::Object^ sender, System::EventArgs^ e) {
		EmailClient::ProfilesForm^ profilesForm = gcnew EmailClient::ProfilesForm();
		profilesForm->ProfilesChanged += gcnew ProfilesChangedEventHandler(this, &Gui::updateProfileBox);
		profilesForm->Show();
	}
	private: System::Void updateProfileBox() {
		currentProfileBox->Items->Clear();
		List<ProfileDTO^>^ profiles = AuthProfileManager::getInstance()->getProfiles();
		for each (ProfileDTO ^ profile in profiles) {
			currentProfileBox->Items->Add(profile->Title);
		}
	}

	private: System::Void selectedProfileChanged(System::Object^ sender, System::EventArgs^ e) {
		String^ selectedProfileTitle = dynamic_cast<String^>(currentProfileBox->SelectedItem);
		if (selectedProfileTitle != nullptr) {
			AuthProfileManager::getInstance()->setCurrentProfileByTitle(selectedProfileTitle);
		}
	}
};
}