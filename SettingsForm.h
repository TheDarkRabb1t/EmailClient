#pragma once

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


	private: System::Windows::Forms::DataGridView^ dataGridView1;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->PropertyName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PropertyValue = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->applySettingsButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->settingsGridSaveBSplit))->BeginInit();
			this->settingsGridSaveBSplit->Panel1->SuspendLayout();
			this->settingsGridSaveBSplit->Panel2->SuspendLayout();
			this->settingsGridSaveBSplit->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
			this->settingsGridSaveBSplit->Panel1->Controls->Add(this->dataGridView1);
			this->settingsGridSaveBSplit->Panel1MinSize = 400;
			// 
			// settingsGridSaveBSplit.Panel2
			// 
			this->settingsGridSaveBSplit->Panel2->Controls->Add(this->applySettingsButton);
			this->settingsGridSaveBSplit->Size = System::Drawing::Size(318, 453);
			this->settingsGridSaveBSplit->SplitterDistance = 400;
			this->settingsGridSaveBSplit->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->PropertyName,
					this->PropertyValue
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(318, 400);
			this->dataGridView1->TabIndex = 0;
			// 
			// PropertyName
			// 
			this->PropertyName->HeaderText = L"Property";
			this->PropertyName->Name = L"PropertyName";
			// 
			// PropertyValue
			// 
			this->PropertyValue->HeaderText = L"Value";
			this->PropertyValue->Name = L"PropertyValue";
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
