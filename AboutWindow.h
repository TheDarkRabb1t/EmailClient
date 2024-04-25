#pragma once

namespace EmailClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AboutWindow
	/// </summary>
	public ref class AboutWindow : public System::Windows::Forms::Form
	{
	public:
		AboutWindow(void)
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
		~AboutWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ headerBodySplitC;
	protected:

	private: System::Windows::Forms::SplitContainer^ imageShortDescriptionSplitC;
	protected:

	private: System::Windows::Forms::TextBox^ aboutBodyText;
	private: System::Windows::Forms::TextBox^ shortDescription;

	private: System::Windows::Forms::PictureBox^ appLogoPicture;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AboutWindow::typeid));
			this->headerBodySplitC = (gcnew System::Windows::Forms::SplitContainer());
			this->imageShortDescriptionSplitC = (gcnew System::Windows::Forms::SplitContainer());
			this->appLogoPicture = (gcnew System::Windows::Forms::PictureBox());
			this->shortDescription = (gcnew System::Windows::Forms::TextBox());
			this->aboutBodyText = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->headerBodySplitC))->BeginInit();
			this->headerBodySplitC->Panel1->SuspendLayout();
			this->headerBodySplitC->Panel2->SuspendLayout();
			this->headerBodySplitC->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageShortDescriptionSplitC))->BeginInit();
			this->imageShortDescriptionSplitC->Panel1->SuspendLayout();
			this->imageShortDescriptionSplitC->Panel2->SuspendLayout();
			this->imageShortDescriptionSplitC->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->appLogoPicture))->BeginInit();
			this->SuspendLayout();
			// 
			// headerBodySplitC
			// 
			this->headerBodySplitC->Dock = System::Windows::Forms::DockStyle::Fill;
			this->headerBodySplitC->Location = System::Drawing::Point(0, 0);
			this->headerBodySplitC->Name = L"headerBodySplitC";
			this->headerBodySplitC->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// headerBodySplitC.Panel1
			// 
			this->headerBodySplitC->Panel1->Controls->Add(this->imageShortDescriptionSplitC);
			// 
			// headerBodySplitC.Panel2
			// 
			this->headerBodySplitC->Panel2->Controls->Add(this->aboutBodyText);
			this->headerBodySplitC->Size = System::Drawing::Size(348, 325);
			this->headerBodySplitC->SplitterDistance = 115;
			this->headerBodySplitC->TabIndex = 0;
			// 
			// imageShortDescriptionSplitC
			// 
			this->imageShortDescriptionSplitC->Dock = System::Windows::Forms::DockStyle::Fill;
			this->imageShortDescriptionSplitC->Location = System::Drawing::Point(0, 0);
			this->imageShortDescriptionSplitC->Name = L"imageShortDescriptionSplitC";
			// 
			// imageShortDescriptionSplitC.Panel1
			// 
			this->imageShortDescriptionSplitC->Panel1->Controls->Add(this->appLogoPicture);
			// 
			// imageShortDescriptionSplitC.Panel2
			// 
			this->imageShortDescriptionSplitC->Panel2->Controls->Add(this->shortDescription);
			this->imageShortDescriptionSplitC->Size = System::Drawing::Size(348, 115);
			this->imageShortDescriptionSplitC->SplitterDistance = 140;
			this->imageShortDescriptionSplitC->TabIndex = 0;
			// 
			// appLogoPicture
			// 
			this->appLogoPicture->Dock = System::Windows::Forms::DockStyle::Fill;
			this->appLogoPicture->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"appLogoPicture.Image")));
			this->appLogoPicture->Location = System::Drawing::Point(0, 0);
			this->appLogoPicture->Name = L"appLogoPicture";
			this->appLogoPicture->Size = System::Drawing::Size(140, 115);
			this->appLogoPicture->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->appLogoPicture->TabIndex = 0;
			this->appLogoPicture->TabStop = false;
			// 
			// shortDescription
			// 
			this->shortDescription->Dock = System::Windows::Forms::DockStyle::Fill;
			this->shortDescription->Location = System::Drawing::Point(0, 0);
			this->shortDescription->Multiline = true;
			this->shortDescription->Name = L"shortDescription";
			this->shortDescription->ReadOnly = true;
			this->shortDescription->Size = System::Drawing::Size(204, 115);
			this->shortDescription->TabIndex = 0;
			this->shortDescription->Text = L"EmailClient\r\nversion 1.0.0.0\r\n\r\nKhytrych Stanislav\r\nCopytright ©2024\r\nMIT LICENSE"
				L"";
			this->shortDescription->TextChanged += gcnew System::EventHandler(this, &AboutWindow::textBox1_TextChanged);
			// 
			// aboutBodyText
			// 
			this->aboutBodyText->Dock = System::Windows::Forms::DockStyle::Fill;
			this->aboutBodyText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->aboutBodyText->Location = System::Drawing::Point(0, 0);
			this->aboutBodyText->Multiline = true;
			this->aboutBodyText->Name = L"aboutBodyText";
			this->aboutBodyText->ReadOnly = true;
			this->aboutBodyText->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->aboutBodyText->Size = System::Drawing::Size(348, 206);
			this->aboutBodyText->TabIndex = 0;
			this->aboutBodyText->Text = resources->GetString(L"aboutBodyText.Text");
			// 
			// AboutWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(348, 325);
			this->Controls->Add(this->headerBodySplitC);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"AboutWindow";
			this->Text = L"About Window";
			this->headerBodySplitC->Panel1->ResumeLayout(false);
			this->headerBodySplitC->Panel2->ResumeLayout(false);
			this->headerBodySplitC->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->headerBodySplitC))->EndInit();
			this->headerBodySplitC->ResumeLayout(false);
			this->imageShortDescriptionSplitC->Panel1->ResumeLayout(false);
			this->imageShortDescriptionSplitC->Panel1->PerformLayout();
			this->imageShortDescriptionSplitC->Panel2->ResumeLayout(false);
			this->imageShortDescriptionSplitC->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imageShortDescriptionSplitC))->EndInit();
			this->imageShortDescriptionSplitC->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->appLogoPicture))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
