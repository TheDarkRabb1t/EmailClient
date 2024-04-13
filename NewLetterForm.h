#pragma once
#include "system/service/AsyncEmailService.h"
#include "system/AuthProfileManager.h"
#include "model/OutgoingEmailDTO.h"
#include "system/Config.h"

namespace EmailClient {

	/// <summary>
	/// Summary for NewLetterForm
	/// </summary>
	public ref class NewLetterForm : public System::Windows::Forms::Form
	{
	public:
		NewLetterForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NewLetterForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ emailFormSendButtonSplit;










	private: System::Windows::Forms::GroupBox^ bodyGroupBox;

	private: System::Windows::Forms::GroupBox^ topFormGroupBox;
	private: System::Windows::Forms::RichTextBox^ emailBody;
	private: System::Windows::Forms::TextBox^ emailSubject;
	private: System::Windows::Forms::TextBox^ emailTo;
	private: System::Windows::Forms::Button^ sendButton;







	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NewLetterForm::typeid));
			this->emailFormSendButtonSplit = (gcnew System::Windows::Forms::SplitContainer());
			this->bodyGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->emailBody = (gcnew System::Windows::Forms::RichTextBox());
			this->emailSubject = (gcnew System::Windows::Forms::TextBox());
			this->topFormGroupBox = (gcnew System::Windows::Forms::GroupBox());
			this->emailTo = (gcnew System::Windows::Forms::TextBox());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->emailFormSendButtonSplit))->BeginInit();
			this->emailFormSendButtonSplit->Panel1->SuspendLayout();
			this->emailFormSendButtonSplit->Panel2->SuspendLayout();
			this->emailFormSendButtonSplit->SuspendLayout();
			this->bodyGroupBox->SuspendLayout();
			this->topFormGroupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// emailFormSendButtonSplit
			// 
			this->emailFormSendButtonSplit->Dock = System::Windows::Forms::DockStyle::Fill;
			this->emailFormSendButtonSplit->Location = System::Drawing::Point(0, 0);
			this->emailFormSendButtonSplit->Name = L"emailFormSendButtonSplit";
			this->emailFormSendButtonSplit->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// emailFormSendButtonSplit.Panel1
			// 
			this->emailFormSendButtonSplit->Panel1->Controls->Add(this->bodyGroupBox);
			this->emailFormSendButtonSplit->Panel1->Controls->Add(this->topFormGroupBox);
			this->emailFormSendButtonSplit->Panel1MinSize = 150;
			// 
			// emailFormSendButtonSplit.Panel2
			// 
			this->emailFormSendButtonSplit->Panel2->Controls->Add(this->sendButton);
			this->emailFormSendButtonSplit->Panel2MinSize = 40;
			this->emailFormSendButtonSplit->Size = System::Drawing::Size(356, 340);
			this->emailFormSendButtonSplit->SplitterDistance = 296;
			this->emailFormSendButtonSplit->TabIndex = 0;
			// 
			// bodyGroupBox
			// 
			this->bodyGroupBox->Controls->Add(this->emailBody);
			this->bodyGroupBox->Controls->Add(this->emailSubject);
			this->bodyGroupBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->bodyGroupBox->Location = System::Drawing::Point(0, 44);
			this->bodyGroupBox->MinimumSize = System::Drawing::Size(0, 252);
			this->bodyGroupBox->Name = L"bodyGroupBox";
			this->bodyGroupBox->Size = System::Drawing::Size(356, 252);
			this->bodyGroupBox->TabIndex = 3;
			this->bodyGroupBox->TabStop = false;
			this->bodyGroupBox->Text = L"Subject And Body";
			// 
			// emailBody
			// 
			this->emailBody->Dock = System::Windows::Forms::DockStyle::Fill;
			this->emailBody->Location = System::Drawing::Point(3, 36);
			this->emailBody->Name = L"emailBody";
			this->emailBody->Size = System::Drawing::Size(350, 213);
			this->emailBody->TabIndex = 1;
			this->emailBody->Text = L"";
			// 
			// emailSubject
			// 
			this->emailSubject->Dock = System::Windows::Forms::DockStyle::Top;
			this->emailSubject->Location = System::Drawing::Point(3, 16);
			this->emailSubject->Name = L"emailSubject";
			this->emailSubject->Size = System::Drawing::Size(350, 20);
			this->emailSubject->TabIndex = 0;
			// 
			// topFormGroupBox
			// 
			this->topFormGroupBox->Controls->Add(this->emailTo);
			this->topFormGroupBox->Dock = System::Windows::Forms::DockStyle::Top;
			this->topFormGroupBox->Location = System::Drawing::Point(0, 0);
			this->topFormGroupBox->MinimumSize = System::Drawing::Size(0, 44);
			this->topFormGroupBox->Name = L"topFormGroupBox";
			this->topFormGroupBox->Size = System::Drawing::Size(356, 44);
			this->topFormGroupBox->TabIndex = 2;
			this->topFormGroupBox->TabStop = false;
			this->topFormGroupBox->Text = L"Send To";
			this->topFormGroupBox->Enter += gcnew System::EventHandler(this, &NewLetterForm::groupBox1_Enter);
			// 
			// emailTo
			// 
			this->emailTo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->emailTo->Location = System::Drawing::Point(3, 16);
			this->emailTo->Name = L"emailTo";
			this->emailTo->Size = System::Drawing::Size(350, 20);
			this->emailTo->TabIndex = 0;
			// 
			// sendButton
			// 
			this->sendButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sendButton->Location = System::Drawing::Point(0, 0);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(356, 40);
			this->sendButton->TabIndex = 1;
			this->sendButton->Text = L"Send";
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &NewLetterForm::sendNewEmail);
			// 
			// NewLetterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(356, 340);
			this->Controls->Add(this->emailFormSendButtonSplit);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"NewLetterForm";
			this->Text = L"NewLetterForm";
			this->emailFormSendButtonSplit->Panel1->ResumeLayout(false);
			this->emailFormSendButtonSplit->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->emailFormSendButtonSplit))->EndInit();
			this->emailFormSendButtonSplit->ResumeLayout(false);
			this->bodyGroupBox->ResumeLayout(false);
			this->bodyGroupBox->PerformLayout();
			this->topFormGroupBox->ResumeLayout(false);
			this->topFormGroupBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void sendNewEmail(System::Object^ sender, System::EventArgs^ e) {

		ProfileDTO^ senderProfile = AuthProfileManager::getInstance()->getCurrentProfile();
		MailMessage^ email = gcnew System::Net::Mail::MailMessage();
		email->From = senderProfile->email;
		email->Subject = emailSubject->Text;
		email->Body = emailBody->Text;
		email->To->Add(emailTo->Text);

		OutgoingMailDTO^ oMailDTO = gcnew OutgoingMailDTO(senderProfile, email);
		AsyncEmailSender::getInstance()->AppendEmailQueue(oMailDTO);
		this->Close();
	}
	private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}