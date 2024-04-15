#pragma once
#include "system/Config.h";
#include <msclr/marshal_cppstd.h>


namespace EmailClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public:
		SettingsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			std::map<std::string, std::string> configMapCopy = Config::getInstance().getConfigMap();
			int row = 0;
			for (const auto& pair : configMapCopy) {
				settingsGrid->Rows->Add(gcnew array<String^> { gcnew String(pair.first.c_str()), gcnew String(pair.second.c_str()) });
				row++;
			}

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ settingsGridSaveBSplit;
	private: System::Windows::Forms::Button^ applySettingsButton;
	private: System::Windows::Forms::DataGridView^ settingsGrid;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PropertyName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PropertyValue;









	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SettingsForm::typeid));
			this->settingsGridSaveBSplit = (gcnew System::Windows::Forms::SplitContainer());
			this->settingsGrid = (gcnew System::Windows::Forms::DataGridView());
			this->PropertyName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PropertyValue = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->applySettingsButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->settingsGridSaveBSplit))->BeginInit();
			this->settingsGridSaveBSplit->Panel1->SuspendLayout();
			this->settingsGridSaveBSplit->Panel2->SuspendLayout();
			this->settingsGridSaveBSplit->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->settingsGrid))->BeginInit();
			this->SuspendLayout();
			// 
			// settingsGridSaveBSplit
			// 
			this->settingsGridSaveBSplit->Dock = System::Windows::Forms::DockStyle::Fill;
			this->settingsGridSaveBSplit->Location = System::Drawing::Point(0, 0);
			this->settingsGridSaveBSplit->Name = L"settingsGridSaveBSplit";
			this->settingsGridSaveBSplit->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// settingsGridSaveBSplit.Panel1
			// 
			this->settingsGridSaveBSplit->Panel1->Controls->Add(this->settingsGrid);
			this->settingsGridSaveBSplit->Panel1MinSize = 400;
			// 
			// settingsGridSaveBSplit.Panel2
			// 
			this->settingsGridSaveBSplit->Panel2->Controls->Add(this->applySettingsButton);
			this->settingsGridSaveBSplit->Size = System::Drawing::Size(318, 453);
			this->settingsGridSaveBSplit->SplitterDistance = 400;
			this->settingsGridSaveBSplit->TabIndex = 0;
			// 
			// settingsGrid
			// 
			this->settingsGrid->AllowUserToAddRows = false;
			this->settingsGrid->AllowUserToDeleteRows = false;
			this->settingsGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->settingsGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->settingsGrid->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->PropertyName,
					this->PropertyValue
			});
			this->settingsGrid->Location = System::Drawing::Point(0, 0);
			this->settingsGrid->Name = L"settingsGrid";
			this->settingsGrid->Size = System::Drawing::Size(318, 400);
			this->settingsGrid->TabIndex = 0;
			this->settingsGrid->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SettingsForm::settingsGrid_CellContentClick);
			// 
			// PropertyName
			// 
			this->PropertyName->HeaderText = L"Property";
			this->PropertyName->Name = L"PropertyName";
			this->PropertyName->ReadOnly = true;
			this->PropertyName->Width = 150;
			// 
			// PropertyValue
			// 
			this->PropertyValue->HeaderText = L"Value";
			this->PropertyValue->Name = L"PropertyValue";
			this->PropertyValue->Width = 140;
			// 
			// applySettingsButton
			// 
			this->applySettingsButton->Dock = System::Windows::Forms::DockStyle::Fill;
			this->applySettingsButton->Location = System::Drawing::Point(0, 0);
			this->applySettingsButton->Name = L"applySettingsButton";
			this->applySettingsButton->Size = System::Drawing::Size(318, 49);
			this->applySettingsButton->TabIndex = 0;
			this->applySettingsButton->Text = L"Apply";
			this->applySettingsButton->UseVisualStyleBackColor = true;
			this->applySettingsButton->Click += gcnew System::EventHandler(this, &SettingsForm::applySettings);
			// 
			// SettingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(318, 453);
			this->Controls->Add(this->settingsGridSaveBSplit);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"SettingsForm";
			this->Text = L"SettingsForm";
			this->settingsGridSaveBSplit->Panel1->ResumeLayout(false);
			this->settingsGridSaveBSplit->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->settingsGridSaveBSplit))->EndInit();
			this->settingsGridSaveBSplit->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->settingsGrid))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		// Inside the SettingsForm class
			private: System::Void applySettings(System::Object^ sender, System::EventArgs^ e) {
			Config& configInstance = Config::getInstance();
			for each (DataGridViewRow ^ row in settingsGrid->Rows) {
				if (row->Cells["PropertyName"]->Value && row->Cells["PropertyValue"]->Value) {
					std::string key = msclr::interop::marshal_as<std::string>(row->Cells["PropertyName"]->Value->ToString());
					std::string value = msclr::interop::marshal_as<std::string>(row->Cells["PropertyValue"]->Value->ToString());
					configInstance.setValue(key, value);
				}
			}
			configInstance.saveConfig();
			this->Close();
			}

private: System::Void settingsGrid_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}
