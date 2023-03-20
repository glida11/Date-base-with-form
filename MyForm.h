#pragma once
#include <fstream>
#include <iostream>
#include <windows.h> 
#include <stringapiset.h>

#define SIZE_STRING 256
#define SROOM 500
using namespace std;
struct Date
{
	int day;
	char* month;
	int year;
};
bool Verification(int d, int m, int y)
{
	if (m < 0 || d < 0 || y < 0)
		return 0;
	int numDaysNoVis[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int numDaysVis[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (m > 12)
		return 0;
	if ((y % 4 == 0 && y % 100 != 0 || y % 400) && numDaysVis[m] < d || numDaysNoVis[m] < d)
		return 0;
	return 1;
}
//{ "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}
int copyto(char* buf, System::String^ S, int count)
{
	int i, state;
	for (i = 0; i < S->Length; i++)
	{
		if (i >= count) break;
		wchar_t t = (*S)[i];
		state = WideCharToMultiByte(CP_ACP, 0, &t, 1, &buf[i], 1, NULL, NULL);
	}
	buf[i] = '\0';
	return state;
}
int intMonth(System::String^ Text)
{
	char** MMonth = new char* [12];
	for (int i = 0; i < 12; i++)
	{
		MMonth[i] = new char[12];
	}
	MMonth[0] = "January";
	MMonth[1] = "February";
	MMonth[2] = "March";
	MMonth[3] = "April";
	MMonth[4] = "May";
	MMonth[5] = "June";
	MMonth[6] = "July";
	MMonth[7] = "August";
	MMonth[8] = "September";
	MMonth[9] = "October";
	MMonth[10] = "November";
	MMonth[11] = "December";
	char** Mmonth = new char* [12];
	for (int i = 0; i < 12; i++)
	{
		Mmonth[i] = new char[12];
	}
	Mmonth[0] = "january";
	Mmonth[1] = "february";
	Mmonth[2] = "march";
	Mmonth[3] = "april";
	Mmonth[4] = "may";
	Mmonth[5] = "june";
	Mmonth[6] = "july";
	Mmonth[7] = "august";
	Mmonth[8] = "september";
	Mmonth[9] = "october";
	Mmonth[10] = "november";
	Mmonth[11] = "december";
	char* Month = new char[SIZE_STRING];
	copyto(Month, Text, SIZE_STRING);
	for (int i = 0; i < 12; i++)
	{
		if (!strcmp(Month, MMonth[i]) || !strcmp(Month, Mmonth[i]))
			return i + 1;
	}
}
int charTOint(char* str)
{
	int c = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		c += (str[strlen(str) - i - 1] - '0') * pow(10, i);
	}
	return c;
}
int charTOint(System::String^ Text)
{
	char* str = new char[SIZE_STRING];
	copyto(str, Text, SIZE_STRING);
	int c = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		c += (str[strlen(str) - i - 1] - '0') * pow(10, i);
	}
	return c;
}
int len(int d)
{
	int i;
	for (i = 0; d >= 1; i++)
		d /= 10;
	return i;
}

namespace My6Laba {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBoxNameVIS;
	private: System::Windows::Forms::TextBox^ textBoxAddress;
	protected:


	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListView^ listView1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;




	private: System::Windows::Forms::TextBox^ textBoxPrice;

	private: System::Windows::Forms::TextBox^ textBoxCat;
	private: System::Windows::Forms::TextBox^ textBoxPhone;




	private: System::Windows::Forms::TextBox^ textBoxNameADM;
	private: System::Windows::Forms::TextBox^ textBoxArrDay;






	private: System::Windows::Forms::Button^ ButtonAdd;
	private: System::Windows::Forms::Button^ ButtonDelete;


	private: System::Windows::Forms::Button^ ButtonSearch;
	private: System::Windows::Forms::Button^ ButtonNext;




	private: System::Windows::Forms::Button^ ButtonReplace;
	private: System::Windows::Forms::Button^ ButtonClear;
	private: System::Windows::Forms::ColumnHeader^ columnHeader1;
	private: System::Windows::Forms::ColumnHeader^ columnHeader2;
	private: System::Windows::Forms::ColumnHeader^ columnHeader3;
	private: System::Windows::Forms::ColumnHeader^ columnHeader4;

	private: System::Windows::Forms::ColumnHeader^ columnHeader6;
	private: System::Windows::Forms::ColumnHeader^ columnHeader7;
	private: System::Windows::Forms::ColumnHeader^ columnHeader8;
	private: System::Windows::Forms::ColumnHeader^ columnHeader9;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;

	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::GroupBox^ groupBox5;

	private: System::Windows::Forms::MenuStrip^ menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^ FailToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ сохранитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ загрузитьToolStripMenuItem;
	private: System::Windows::Forms::ColumnHeader^ columnHeader11;
	private: System::Windows::Forms::ColumnHeader^ columnHeader12;




	private: System::Windows::Forms::TextBox^ textBoxArrYear;
	private: System::Windows::Forms::TextBox^ textBoxArrMonth;
	private: System::Windows::Forms::Label^ label10;











private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;

private: System::Windows::Forms::Button^ buttonSorting;

private: System::Windows::Forms::ToolStripMenuItem^ editToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ addToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ searchToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ replaceToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ deleteToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ nextToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ clearToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^ requestsToolStripMenuItem;

private: System::Windows::Forms::GroupBox^ groupBox7;
private: System::Windows::Forms::ComboBox^ comboBox1;
private: System::Windows::Forms::RadioButton^ radioButton2;
private: System::Windows::Forms::RadioButton^ radioButton1;








private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::ToolStripMenuItem^ sortingToolStripMenuItem;











	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBoxNameVIS = (gcnew System::Windows::Forms::TextBox());
			this->textBoxAddress = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader8 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader9 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader11 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader12 = (gcnew System::Windows::Forms::ColumnHeader());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBoxPrice = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCat = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPhone = (gcnew System::Windows::Forms::TextBox());
			this->textBoxNameADM = (gcnew System::Windows::Forms::TextBox());
			this->textBoxArrDay = (gcnew System::Windows::Forms::TextBox());
			this->ButtonAdd = (gcnew System::Windows::Forms::Button());
			this->ButtonDelete = (gcnew System::Windows::Forms::Button());
			this->ButtonSearch = (gcnew System::Windows::Forms::Button());
			this->ButtonNext = (gcnew System::Windows::Forms::Button());
			this->ButtonReplace = (gcnew System::Windows::Forms::Button());
			this->ButtonClear = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->textBoxArrYear = (gcnew System::Windows::Forms::TextBox());
			this->textBoxArrMonth = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->buttonSorting = (gcnew System::Windows::Forms::Button());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->FailToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->сохранитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->загрузитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->searchToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->replaceToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nextToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->requestsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortingToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->menuStrip2->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBoxNameVIS
			// 
			this->textBoxNameVIS->Location = System::Drawing::Point(67, 25);
			this->textBoxNameVIS->Name = L"textBoxNameVIS";
			this->textBoxNameVIS->Size = System::Drawing::Size(100, 20);
			this->textBoxNameVIS->TabIndex = 0;
			this->textBoxNameVIS->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBoxAll_TextChanged);
			this->textBoxNameVIS->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxNameVIS_KeyPress);
			// 
			// textBoxAddress
			// 
			this->textBoxAddress->Location = System::Drawing::Point(67, 51);
			this->textBoxAddress->Name = L"textBoxAddress";
			this->textBoxAddress->Size = System::Drawing::Size(100, 20);
			this->textBoxAddress->TabIndex = 1;
			this->textBoxAddress->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBoxAll_TextChanged);
			this->textBoxAddress->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxAddress_KeyPress);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Имя";
			// 
			// listView1
			// 
			this->listView1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(10) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader6, this->columnHeader7, this->columnHeader8, this->columnHeader9,
					this->columnHeader11, this->columnHeader12
			});
			this->listView1->Cursor = System::Windows::Forms::Cursors::Default;
			this->listView1->GridLines = true;
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(86, 27);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(614, 204);
			this->listView1->TabIndex = 3;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"№";
			this->columnHeader1->Width = 25;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Клиент";
			this->columnHeader2->Width = 65;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Адрес";
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Стоимость";
			this->columnHeader4->Width = 77;
			// 
			// columnHeader6
			// 
			this->columnHeader6->Text = L"Адрес Бюро";
			this->columnHeader6->Width = 86;
			// 
			// columnHeader7
			// 
			this->columnHeader7->Text = L"Бюро";
			this->columnHeader7->Width = 67;
			// 
			// columnHeader8
			// 
			this->columnHeader8->Text = L"Телефон";
			this->columnHeader8->Width = 80;
			// 
			// columnHeader9
			// 
			this->columnHeader9->Text = L"День";
			this->columnHeader9->Width = 42;
			// 
			// columnHeader11
			// 
			this->columnHeader11->Text = L"Месяц";
			this->columnHeader11->Width = 59;
			// 
			// columnHeader12
			// 
			this->columnHeader12->Text = L"Год";
			this->columnHeader12->Width = 51;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(38, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Адрес";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(246, 265);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(98, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Стоимость услуги";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(26, 54);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Название";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(11, 54);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(37, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Month";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(22, 28);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(26, 13);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Day";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(9, 80);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(52, 13);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Телефон";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(26, 80);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(38, 13);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Адрес";
			// 
			// textBoxPrice
			// 
			this->textBoxPrice->Location = System::Drawing::Point(130, 25);
			this->textBoxPrice->Name = L"textBoxPrice";
			this->textBoxPrice->Size = System::Drawing::Size(100, 20);
			this->textBoxPrice->TabIndex = 16;
			this->textBoxPrice->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBoxAll_TextChanged);
			this->textBoxPrice->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxPrice_KeyPress);
			// 
			// textBoxCat
			// 
			this->textBoxCat->Location = System::Drawing::Point(130, 77);
			this->textBoxCat->Name = L"textBoxCat";
			this->textBoxCat->Size = System::Drawing::Size(100, 20);
			this->textBoxCat->TabIndex = 18;
			this->textBoxCat->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBoxAll_TextChanged);
			this->textBoxCat->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxCat_KeyPress);
			// 
			// textBoxPhone
			// 
			this->textBoxPhone->Location = System::Drawing::Point(67, 77);
			this->textBoxPhone->Name = L"textBoxPhone";
			this->textBoxPhone->Size = System::Drawing::Size(100, 20);
			this->textBoxPhone->TabIndex = 19;
			this->textBoxPhone->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBoxAll_TextChanged);
			this->textBoxPhone->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxPhone_KeyPress);
			// 
			// textBoxNameADM
			// 
			this->textBoxNameADM->Location = System::Drawing::Point(130, 51);
			this->textBoxNameADM->Name = L"textBoxNameADM";
			this->textBoxNameADM->Size = System::Drawing::Size(100, 20);
			this->textBoxNameADM->TabIndex = 20;
			this->textBoxNameADM->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBoxAll_TextChanged);
			this->textBoxNameADM->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxNameADM_KeyPress);
			// 
			// textBoxArrDay
			// 
			this->textBoxArrDay->Location = System::Drawing::Point(72, 25);
			this->textBoxArrDay->Name = L"textBoxArrDay";
			this->textBoxArrDay->Size = System::Drawing::Size(32, 20);
			this->textBoxArrDay->TabIndex = 21;
			this->textBoxArrDay->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxArr_TextChanged);
			this->textBoxArrDay->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxArrDay_KeyPress);
			// 
			// ButtonAdd
			// 
			this->ButtonAdd->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ButtonAdd->Enabled = false;
			this->ButtonAdd->Location = System::Drawing::Point(15, 22);
			this->ButtonAdd->Name = L"ButtonAdd";
			this->ButtonAdd->Size = System::Drawing::Size(75, 23);
			this->ButtonAdd->TabIndex = 23;
			this->ButtonAdd->Text = L"Добавить";
			this->ButtonAdd->UseVisualStyleBackColor = true;
			this->ButtonAdd->Click += gcnew System::EventHandler(this, &MyForm::ButtonAdd_Click);
			// 
			// ButtonDelete
			// 
			this->ButtonDelete->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ButtonDelete->Location = System::Drawing::Point(96, 22);
			this->ButtonDelete->Name = L"ButtonDelete";
			this->ButtonDelete->Size = System::Drawing::Size(75, 23);
			this->ButtonDelete->TabIndex = 24;
			this->ButtonDelete->Text = L"Удалить";
			this->ButtonDelete->UseVisualStyleBackColor = true;
			this->ButtonDelete->Click += gcnew System::EventHandler(this, &MyForm::ButtonDelete_Click);
			// 
			// ButtonSearch
			// 
			this->ButtonSearch->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ButtonSearch->Location = System::Drawing::Point(15, 48);
			this->ButtonSearch->Name = L"ButtonSearch";
			this->ButtonSearch->Size = System::Drawing::Size(75, 23);
			this->ButtonSearch->TabIndex = 25;
			this->ButtonSearch->Text = L"Найти";
			this->ButtonSearch->UseVisualStyleBackColor = true;
			this->ButtonSearch->Click += gcnew System::EventHandler(this, &MyForm::ButtonSearch_Click);
			// 
			// ButtonNext
			// 
			this->ButtonNext->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ButtonNext->Location = System::Drawing::Point(15, 74);
			this->ButtonNext->Name = L"ButtonNext";
			this->ButtonNext->Size = System::Drawing::Size(75, 23);
			this->ButtonNext->TabIndex = 26;
			this->ButtonNext->Text = L"Следующий";
			this->ButtonNext->UseVisualStyleBackColor = true;
			this->ButtonNext->Click += gcnew System::EventHandler(this, &MyForm::ButtonNext_Click);
			// 
			// ButtonReplace
			// 
			this->ButtonReplace->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ButtonReplace->Location = System::Drawing::Point(96, 48);
			this->ButtonReplace->Name = L"ButtonReplace";
			this->ButtonReplace->Size = System::Drawing::Size(75, 23);
			this->ButtonReplace->TabIndex = 27;
			this->ButtonReplace->Text = L"Заменить";
			this->ButtonReplace->UseVisualStyleBackColor = true;
			this->ButtonReplace->Click += gcnew System::EventHandler(this, &MyForm::ButtonReplace_Click);
			// 
			// ButtonClear
			// 
			this->ButtonClear->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ButtonClear->Location = System::Drawing::Point(96, 74);
			this->ButtonClear->Name = L"ButtonClear";
			this->ButtonClear->Size = System::Drawing::Size(75, 23);
			this->ButtonClear->TabIndex = 28;
			this->ButtonClear->Text = L"Очистить таблицу";
			this->ButtonClear->UseVisualStyleBackColor = true;
			this->ButtonClear->Click += gcnew System::EventHandler(this, &MyForm::ButtonClear_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->textBoxPhone);
			this->groupBox1->Controls->Add(this->textBoxAddress);
			this->groupBox1->Controls->Add(this->textBoxNameVIS);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(19, 237);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(179, 110);
			this->groupBox1->TabIndex = 29;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Клиент";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBoxNameADM);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->textBoxPrice);
			this->groupBox2->Controls->Add(this->textBoxCat);
			this->groupBox2->Controls->Add(this->label9);
			this->groupBox2->Location = System::Drawing::Point(220, 237);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(262, 110);
			this->groupBox2->TabIndex = 30;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Бюро";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBoxArrYear);
			this->groupBox4->Controls->Add(this->textBoxArrMonth);
			this->groupBox4->Controls->Add(this->label10);
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Controls->Add(this->textBoxArrDay);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Location = System::Drawing::Point(19, 352);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(141, 110);
			this->groupBox4->TabIndex = 30;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Дата приема анкеты";
			// 
			// textBoxArrYear
			// 
			this->textBoxArrYear->Location = System::Drawing::Point(72, 77);
			this->textBoxArrYear->Name = L"textBoxArrYear";
			this->textBoxArrYear->Size = System::Drawing::Size(49, 20);
			this->textBoxArrYear->TabIndex = 35;
			this->textBoxArrYear->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxArr_TextChanged);
			this->textBoxArrYear->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxArrYear_KeyPress);
			// 
			// textBoxArrMonth
			// 
			this->textBoxArrMonth->Location = System::Drawing::Point(72, 51);
			this->textBoxArrMonth->Name = L"textBoxArrMonth";
			this->textBoxArrMonth->Size = System::Drawing::Size(62, 20);
			this->textBoxArrMonth->TabIndex = 34;
			this->textBoxArrMonth->TextChanged += gcnew System::EventHandler(this, &MyForm::textBoxArr_TextChanged);
			this->textBoxArrMonth->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBoxArrMonth_KeyPress);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(19, 80);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(29, 13);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Year";
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->buttonSorting);
			this->groupBox5->Controls->Add(this->label15);
			this->groupBox5->Controls->Add(this->textBox1);
			this->groupBox5->Controls->Add(this->ButtonClear);
			this->groupBox5->Controls->Add(this->ButtonReplace);
			this->groupBox5->Controls->Add(this->ButtonAdd);
			this->groupBox5->Controls->Add(this->ButtonNext);
			this->groupBox5->Controls->Add(this->ButtonDelete);
			this->groupBox5->Controls->Add(this->ButtonSearch);
			this->groupBox5->Location = System::Drawing::Point(183, 353);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(267, 115);
			this->groupBox5->TabIndex = 31;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Кнопки";
			// 
			// buttonSorting
			// 
			this->buttonSorting->Location = System::Drawing::Point(174, 74);
			this->buttonSorting->Name = L"buttonSorting";
			this->buttonSorting->Size = System::Drawing::Size(87, 23);
			this->buttonSorting->TabIndex = 0;
			this->buttonSorting->Text = L"Сортировать";
			this->buttonSorting->UseVisualStyleBackColor = true;
			this->buttonSorting->Click += gcnew System::EventHandler(this, &MyForm::buttonSorting_Click);
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(174, 48);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(18, 13);
			this->label15->TabIndex = 33;
			this->label15->Text = L"№";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(198, 45);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(33, 20);
			this->textBox1->TabIndex = 32;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox1_KeyPress);
			// 
			// menuStrip2
			// 
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->FailToolStripMenuItem,
					this->editToolStripMenuItem, this->requestsToolStripMenuItem
			});
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(789, 24);
			this->menuStrip2->TabIndex = 33;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// FailToolStripMenuItem
			// 
			this->FailToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->сохранитьToolStripMenuItem,
					this->загрузитьToolStripMenuItem
			});
			this->FailToolStripMenuItem->Name = L"FailToolStripMenuItem";
			this->FailToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->FailToolStripMenuItem->Text = L"Файл";
			// 
			// сохранитьToolStripMenuItem
			// 
			this->сохранитьToolStripMenuItem->Name = L"сохранитьToolStripMenuItem";
			this->сохранитьToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->сохранитьToolStripMenuItem->Text = L"Сохранить";
			this->сохранитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::SaveToolStripMenuItem_Click);
			// 
			// загрузитьToolStripMenuItem
			// 
			this->загрузитьToolStripMenuItem->Name = L"загрузитьToolStripMenuItem";
			this->загрузитьToolStripMenuItem->Size = System::Drawing::Size(133, 22);
			this->загрузитьToolStripMenuItem->Text = L"Загрузить";
			this->загрузитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::LoadToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->addToolStripMenuItem,
					this->searchToolStripMenuItem, this->replaceToolStripMenuItem, this->deleteToolStripMenuItem, this->nextToolStripMenuItem, this->clearToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(59, 20);
			this->editToolStripMenuItem->Text = L"Правка";
			// 
			// addToolStripMenuItem
			// 
			this->addToolStripMenuItem->Name = L"addToolStripMenuItem";
			this->addToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->addToolStripMenuItem->Text = L"Добавить";
			this->addToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ButtonAdd_Click);
			// 
			// searchToolStripMenuItem
			// 
			this->searchToolStripMenuItem->Name = L"searchToolStripMenuItem";
			this->searchToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->searchToolStripMenuItem->Text = L"Найти";
			this->searchToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ButtonSearch_Click);
			// 
			// replaceToolStripMenuItem
			// 
			this->replaceToolStripMenuItem->Name = L"replaceToolStripMenuItem";
			this->replaceToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->replaceToolStripMenuItem->Text = L"Заменить";
			this->replaceToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ButtonReplace_Click);
			// 
			// deleteToolStripMenuItem
			// 
			this->deleteToolStripMenuItem->Name = L"deleteToolStripMenuItem";
			this->deleteToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->deleteToolStripMenuItem->Text = L"Удалить";
			this->deleteToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ButtonDelete_Click);
			// 
			// nextToolStripMenuItem
			// 
			this->nextToolStripMenuItem->Name = L"nextToolStripMenuItem";
			this->nextToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->nextToolStripMenuItem->Text = L"Следующий";
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(174, 22);
			this->clearToolStripMenuItem->Text = L"Очистить таблицу";
			this->clearToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::ButtonClear_Click);
			// 
			// requestsToolStripMenuItem
			// 
			this->requestsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->sortingToolStripMenuItem });
			this->requestsToolStripMenuItem->Name = L"requestsToolStripMenuItem";
			this->requestsToolStripMenuItem->Size = System::Drawing::Size(68, 20);
			this->requestsToolStripMenuItem->Text = L"Запросы";
			// 
			// sortingToolStripMenuItem
			// 
			this->sortingToolStripMenuItem->Name = L"sortingToolStripMenuItem";
			this->sortingToolStripMenuItem->Size = System::Drawing::Size(145, 22);
			this->sortingToolStripMenuItem->Text = L"Сортировать";
			this->sortingToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::buttonSorting_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->comboBox1);
			this->groupBox7->Controls->Add(this->radioButton2);
			this->groupBox7->Controls->Add(this->radioButton1);
			this->groupBox7->Location = System::Drawing::Point(511, 237);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(245, 73);
			this->groupBox7->TabIndex = 36;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Сортировать по";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Имя клиента", L"Стоимость", L"Бюро" });
			this->comboBox1->Location = System::Drawing::Point(118, 19);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 0;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(6, 42);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(93, 17);
			this->radioButton2->TabIndex = 4;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"По убыванию";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 19);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(109, 17);
			this->radioButton1->TabIndex = 3;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"По возрастанию";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(789, 499);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox7);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->menuStrip2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox4);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"6 Лабораторная работа";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		static int curSize = 0;
		static int SearchInd = 0;
		static System::String^ SeachText;
		static int SearchSubItemsInd = 0;
	private: System::Void ButtonAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		//Создаем элемент, хранящий данные новой строки таблицы
		ListViewItem^ item = gcnew ListViewItem();
		item->Text = System::Convert::ToString(++curSize);//Порядковый номер записи
		item->SubItems->Add(this->textBoxNameVIS->Text);//Name Visitor
		item->SubItems->Add(this->textBoxAddress->Text);//Address
		item->SubItems->Add(this->textBoxPrice->Text);//Price
		
		item->SubItems->Add(this->textBoxCat->Text);//Category
		item->SubItems->Add(this->textBoxNameADM->Text);//Name Admin
		item->SubItems->Add(this->textBoxPhone->Text);//Phone admin
		item->SubItems->Add(this->textBoxArrDay->Text);//Date Arrive
		item->SubItems->Add(this->textBoxArrMonth->Text);
		item->SubItems->Add(this->textBoxArrYear->Text);
		
		//Добавляем заполненный массив ячеек к текущей таблице listView1
		this->listView1->Items->Add(item);
		textBoxNameVIS->Clear();
		textBoxAddress->Clear();
		textBoxPrice->Clear();
		
		textBoxCat->Clear();
		textBoxNameADM->Clear();
		textBoxPhone->Clear();
		textBoxArrDay->Clear();
		textBoxArrMonth->Clear();
		textBoxArrYear->Clear();
		
		textBoxNameVIS->Focus();
		return System::Void();
	}
		 
	private: System::Void TextBoxAll_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		if ((textBoxNameVIS->Text->Length == 0) ||
			(textBoxAddress->Text->Length == 0) ||
			(textBoxPrice->Text->Length == 0) ||
			
			(textBoxCat->Text->Length == 0) ||
			(textBoxNameADM->Text->Length == 0) ||
			(textBoxPhone->Text->Length == 0) ||
			
			(textBoxArrDay->Text->Length == 0) ||
			(textBoxArrMonth->Text->Length == 0) ||
			(textBoxArrYear->Text->Length == 0) ||
			textBoxArrDay->Text->Length == 0 ||
			textBoxArrMonth->Text->Length == 0 ||
			textBoxArrYear->Text->Length == 0)
			// В поле редактирования нет данных.
			// Сделать кнопку Добавить недоступной
		{
			ButtonAdd->Enabled = false;
			addToolStripMenuItem->Enabled = false;
		}

		else
			// Сделать кнопку Расчет доступной
			addToolStripMenuItem->Enabled = true;
			ButtonAdd->Enabled = true;
	}
	
	private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		//Если выбрано меньше одного элемента, выходим из функции
		if (this->listView1->SelectedItems->Count < 1)
		{
			return;
		}
		//Если выбрано больше одного элемента, работаем с первым из списка выделенных
		if (this->listView1->SelectedItems[0]->SubItems->Count >= 1)
		{
			this->textBox1->Text = this->listView1->SelectedItems[0]->SubItems[0]->Text;
			this->textBoxNameVIS->Text = this->listView1->SelectedItems[0]->SubItems[1]->Text;
			this->textBoxAddress->Text = this->listView1->SelectedItems[0]->SubItems[2]->Text;
			this->textBoxPrice->Text = this->listView1->SelectedItems[0]->SubItems[3]->Text;
			
			this->textBoxCat->Text = this->listView1->SelectedItems[0]->SubItems[4]->Text;
			this->textBoxNameADM->Text = this->listView1->SelectedItems[0]->SubItems[5]->Text;
			this->textBoxPhone->Text = this->listView1->SelectedItems[0]->SubItems[6]->Text;
			this->textBoxArrDay->Text = this->listView1->SelectedItems[0]->SubItems[7]->Text;
			this->textBoxArrMonth->Text = this->listView1->SelectedItems[0]->SubItems[8]->Text;
			this->textBoxArrYear->Text = this->listView1->SelectedItems[0]->SubItems[9]->Text;
		}
	}
	private: System::Void ButtonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
		int i = -1;
		for (i = 0; i < curSize; i++)
		{
			if (this->listView1->Items[i]->SubItems[1]->Text == this->textBoxNameVIS->Text &&
				this->listView1->Items[i]->SubItems[2]->Text == this->textBoxAddress->Text &&
				this->listView1->Items[i]->SubItems[3]->Text == this->textBoxPrice->Text &&
				
				this->listView1->Items[i]->SubItems[4]->Text == this->textBoxCat->Text &&
				this->listView1->Items[i]->SubItems[5]->Text == this->textBoxNameADM->Text &&
				this->listView1->Items[i]->SubItems[6]->Text == this->textBoxPhone->Text &&
				this->listView1->Items[i]->SubItems[7]->Text == this->textBoxArrDay->Text &&
				this->listView1->Items[i]->SubItems[8]->Text == this->textBoxArrMonth->Text &&
				this->listView1->Items[i]->SubItems[9]->Text == this->textBoxArrYear->Text)
				break;
		}
		if (i >= 0 && i < curSize)
		{
			this->listView1->Items->RemoveAt(i);
			curSize--;
			//Исправляем нумерацию посде удаления записи
			for (int j = i; j < curSize; j++)
			{
				this->listView1->Items[j]->SubItems[0]->Text = Convert::ToString(j +
					1);
			}
		}
		else
		{
			MessageBox::Show("Запись не найдена!", "Ошибка ввода",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	};
private: System::Void ButtonReplace_Click(System::Object^ sender, System::EventArgs^ e) {
		ListViewItem^ item = gcnew ListViewItem();
		item->Text = textBox1->Text;//Порядковый номер записи
		item->SubItems->Add(this->textBoxNameVIS->Text);//Name Visitor
		item->SubItems->Add(this->textBoxAddress->Text);//Address
		item->SubItems->Add(this->textBoxPrice->Text);//Price
		item->SubItems->Add(this->textBoxCat->Text);//Category
		item->SubItems->Add(this->textBoxNameADM->Text);//Name Admin
		item->SubItems->Add(this->textBoxPhone->Text);//Phone admin
		item->SubItems->Add(this->textBoxArrDay->Text);//Date Arrive
		item->SubItems->Add(this->textBoxArrMonth->Text);
		item->SubItems->Add(this->textBoxArrYear->Text);
		listView1->Items->RemoveAt(System::Convert::ToInt32(textBox1->Text)-1);
		listView1->Items->Insert(System::Convert::ToInt32(textBox1->Text)-1, item);
		textBoxNameVIS->Clear();
		textBoxAddress->Clear();
		textBoxPrice->Clear();
		textBoxCat->Clear();
		textBoxNameADM->Clear();
		textBoxPhone->Clear();
		textBoxArrDay->Clear();
		textBoxArrMonth->Clear();
		textBoxArrYear->Clear();
		textBoxNameVIS->Focus();
	}
private: System::Void SaveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	ofstream fout;
	fout.open("MyForm.txt");
	fout << curSize << endl;
	for (int i = 0; i < curSize; i++)
	{
		
		char* bufNameV = new char[SIZE_STRING];
		char* bufAddress = new char[SIZE_STRING];
		char* bufCat = new char[SIZE_STRING];
		char* bufNameA = new char[SIZE_STRING];
		char* bufPhone = new char[SIZE_STRING];
		char* bufmonthA = new char[10];

		copyto(bufNameV, this->listView1->Items[i]->SubItems[1]->Text, SIZE_STRING);//NameVis
		copyto(bufAddress, this->listView1->Items[i]->SubItems[2]->Text, SIZE_STRING);//Address
		copyto(bufCat, this->listView1->Items[i]->SubItems[4]->Text, SIZE_STRING);//Category
		copyto(bufNameA, this->listView1->Items[i]->SubItems[5]->Text, SIZE_STRING);//Name Admin
		copyto(bufPhone, this->listView1->Items[i]->SubItems[6]->Text, SIZE_STRING);//Phone
		copyto(bufmonthA, this->listView1->Items[i]->SubItems[8]->Text, 10);//Arr Month

		fout << bufNameV << endl << bufAddress << endl;
		fout << Convert::ToInt32(this->listView1->Items[i]->SubItems[3]->Text) << endl;//Price
		fout << bufCat << endl << bufNameA << endl << bufPhone << endl;
		fout << Convert::ToInt32(this->listView1->Items[i]->SubItems[7]->Text) << endl;//Arr Day
		fout << bufmonthA << endl;
		fout << Convert::ToInt32(this->listView1->Items[i]->SubItems[9]->Text) << endl;//Arr Year
	}
	fout.close();
}
private: System::Void LoadToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		if (curSize != 0) {
			for (int i = curSize - 1; i > -1; i--)
			{
				this->listView1->Items->RemoveAt(i);
			}
			curSize = 0;
		}// очистили таблицу перед считыванием из файла
		std::ifstream fin;
		fin.open("MyForm.txt");
		if (!fin)
		{
			MessageBox::Show("Невозможно открыть файл.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			curSize = 0;
			return System::Void();
		}
		char* str = new char[256];
		fin.getline(str, 256, '\n');
		if (strlen(str) == 1 && str[0] == '0')
			;
		else
			curSize = charTOint(str);
		if (curSize == 0) return System::Void();
		for (int i = 0; i < curSize; i++) {
			this->listView1->Items->Add(System::Convert::ToString(i + 1));//Порядковый номер записи
			fin.getline(str, 256, '\n');
			this->listView1->Items[i]->SubItems->Add(gcnew System::String(str));//Name Visitor
			fin.getline(str, 256, '\n');
			this->listView1->Items[i]->SubItems->Add(gcnew System::String(str));//Address
			fin.getline(str, 256, '\n');
			this->listView1->Items[i]->SubItems->Add(gcnew System::String(str));//Price
			fin.getline(str, 256, '\n');
			this->listView1->Items[i]->SubItems->Add(gcnew System::String(str));//Category
			fin.getline(str, 256, '\n');
			this->listView1->Items[i]->SubItems->Add(gcnew System::String(str));//Name Admin
			fin.getline(str, 256, '\n');
			this->listView1->Items[i]->SubItems->Add(gcnew System::String(str));//Phone admin
			fin.getline(str, 256, '\n');
			this->listView1->Items[i]->SubItems->Add(gcnew System::String(str));//Date Arrive Day
			fin.getline(str, 256, '\n');
			this->listView1->Items[i]->SubItems->Add(gcnew System::String(str));//Date Arrive Month
			fin.getline(str, 256, '\n');
			this->listView1->Items[i]->SubItems->Add(gcnew System::String(str));//Date Arrive Year
		}

		//Исправляем нумерацию посде удаления записи
		for (int j = 0; j < curSize; j++)
		{
			this->listView1->Items[j]->SubItems[0]->Text = Convert::ToString(j + 1);
		}
		fin.close();
		return System::Void();
	}
private: System::Void ButtonClear_Click(System::Object^ sender, System::EventArgs^ e) {
	//Стираем содержимое таблицы
	this->listView1->Items->Clear();
	curSize = 0;
	textBoxNameVIS->Clear();
	textBoxAddress->Clear();
	textBoxPrice->Clear();
	textBoxCat->Clear();
	textBoxNameADM->Clear();
	textBoxPhone->Clear();
	textBoxArrDay->Clear();
	textBoxArrMonth->Clear();
	textBoxArrYear->Clear();
	textBoxNameVIS->Focus();
}   

private: int Search(System::String^ FindObj, int indFO, int lastInd)
{
	for (int i = lastInd; i < curSize; i++){
		if (listView1->Items[i]->SubItems[indFO]->Text == FindObj){
			this->textBox1->Text = this->listView1->Items[i]->SubItems[0]->Text;
			this->textBoxNameVIS->Text = this->listView1->Items[i]->SubItems[1]->Text;
			this->textBoxAddress->Text = this->listView1->Items[i]->SubItems[2]->Text;
			this->textBoxPrice->Text = this->listView1->Items[i]->SubItems[3]->Text;
			this->textBoxCat->Text = this->listView1->Items[i]->SubItems[4]->Text;
			this->textBoxNameADM->Text = this->listView1->Items[i]->SubItems[5]->Text;
			this->textBoxPhone->Text = this->listView1->Items[i]->SubItems[6]->Text;
			this->textBoxArrDay->Text = this->listView1->Items[i]->SubItems[7]->Text;
			this->textBoxArrMonth->Text = this->listView1->Items[i]->SubItems[8]->Text;
			this->textBoxArrYear->Text = this->listView1->Items[i]->SubItems[9]->Text;
			SeachText = FindObj;
			SearchSubItemsInd = indFO;
			return i;
		}

	}
	return 0;
}
private: System::Void ButtonSearch_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->textBoxNameVIS->Text->Length != 0) {
		SearchInd = Search(this->textBoxNameVIS->Text, 1, 0) + 1;
		return;
	}
	if (this->textBoxAddress->Text->Length != 0) {
		SearchInd = Search(this->textBoxAddress->Text, 2, 0) + 1;
		return;
	}
	if (this->textBoxPrice->Text->Length != 0) {
		SearchInd = Search(this->textBoxPrice->Text, 3, 0) + 1;
		return;
	}
	if (this->textBoxCat->Text->Length != 0) {
		SearchInd = Search(this->textBoxCat->Text, 5, 0) + 1;
		return;
	}
	if (this->textBoxNameADM->Text->Length != 0) {
		SearchInd = Search(this->textBoxNameADM->Text, 6, 0) + 1;
		return;
	}
	if (this->textBoxPhone->Text->Length != 0) {
		SearchInd = Search(this->textBoxPhone->Text, 7, 0) + 1;
		return;
	}
	if (this->textBoxArrDay->Text->Length != 0) {
		SearchInd = Search(this->textBoxArrDay->Text, 8, 0) + 1;
		return;
	}
	if (this->textBoxArrMonth->Text->Length != 0) {
		SearchInd = Search(this->textBoxArrMonth->Text, 9, 0) + 1;
		return;
	}
	if (this->textBoxArrYear->Text->Length != 0) {
		SearchInd = Search(this->textBoxArrYear->Text, 10, 0) + 1;
		return;
	}
}

private: System::Void textBoxNameVIS_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == ' ')
	{
		e->KeyChar = '_';
		return;
	}
	else
		if (Char::IsControl(e->KeyChar))
		{
			if (e->KeyChar == (char)Keys::Enter)
			{
				// Нажата клавиша <Enter>.
				// Переместить курсор в поле Category
				textBoxAddress->Focus();
			}
			return;
		}
}
private: System::Void textBoxAddress_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == ' ')
	{
		e->KeyChar = '_';
		return;
	}
	else
		if (Char::IsControl(e->KeyChar))
		{
			if (e->KeyChar == (char)Keys::Enter)
			{
				// Нажата клавиша <Enter>.
				// Переместить курсор в поле Category
				textBoxPhone->Focus();
			}
			return;
		}
}
private: System::Void textBoxPrice_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar >= '0' && e->KeyChar <= '9')
		//Цифра
		return;
	if (Char::IsControl(e->KeyChar))
	{
		if (e->KeyChar == (char)Keys::Enter)
		{
			// Нажата клавиша <Enter>.
			// Переместить курсор в поле Category
			textBoxNameADM->Focus();
		}
		return;
	}
	// остальные символы запрещены
	e->Handled = true;
}

private: System::Void textBoxCat_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == ' ')
	{
		e->KeyChar = '_';
		return;
	}
	else
		if (Char::IsControl(e->KeyChar))
		{
			if (e->KeyChar == (char)Keys::Enter)
			{
				// Нажата клавиша <Enter>.
				// Переместить курсор в поле Category
				textBoxArrDay->Focus();
			}
			return;
		}
}
private: System::Void textBoxNameADM_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar == ' ')
	{
		e->KeyChar = '_';
		return;
	}
	else
		if (Char::IsControl(e->KeyChar))
		{
			if (e->KeyChar == (char)Keys::Enter)
			{
				// Нажата клавиша <Enter>.
				// Переместить курсор в поле Category
				textBoxCat->Focus();
			}
			return;
		}
}
private: System::Void textBoxPhone_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar >= '0' && e->KeyChar <= '9' || e->KeyChar == '+')
		//Цифра
		return;
	if (Char::IsControl(e->KeyChar))
	{
		if (e->KeyChar == (char)Keys::Enter)
		{
			// Нажата клавиша <Enter>.
			// Переместить курсор в поле Category
			textBoxPrice->Focus();
		}
		return;
	}
	// остальные символы запрещены
	e->Handled = true;
}
private: System::Void textBoxArrDay_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar >= '0' && e->KeyChar <= '9')
		//Цифра
		return;
	if (Char::IsControl(e->KeyChar))
	{
		if (e->KeyChar == (char)Keys::Enter)
		{
			// Нажата клавиша <Enter>.
			// Переместить курсор в поле Category
			textBoxArrMonth->Focus();
		}
		return;
	}
	// остальные символы запрещены
	e->Handled = true;
}
private: System::Void textBoxArrMonth_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	
	if (Char::IsControl(e->KeyChar))
	{
		if (e->KeyChar == (char)Keys::Enter)
		{
			// Нажата клавиша <Enter>.
			// Переместить курсор в поле Category
			textBoxArrYear->Focus();
		}
		return;
	}
}
private: System::Void textBoxArrYear_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar >= '0' && e->KeyChar <= '9')
		//Цифра
		return;
	// остальные символы запрещены
	e->Handled = true;
}

private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	if (e->KeyChar >= '0' && e->KeyChar <= '9')
		return;
	e->Handled = true;
}
	   
private: System::Void textBoxArr_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if ((textBoxNameVIS->Text->Length == 0) ||
		(textBoxAddress->Text->Length == 0) ||
		(textBoxPrice->Text->Length == 0) ||

		(textBoxCat->Text->Length == 0) ||
		(textBoxNameADM->Text->Length == 0) ||
		(textBoxPhone->Text->Length == 0) ||

		(textBoxArrDay->Text->Length == 0) ||
		(textBoxArrMonth->Text->Length == 0) ||
		(textBoxArrYear->Text->Length == 0))
	{
		addToolStripMenuItem->Enabled = false;
		ButtonAdd->Enabled = false;
	}
	if (textBoxArrDay->Text->Length == 0 ||
		textBoxArrMonth->Text->Length == 0 ||
		textBoxArrYear->Text->Length == 0)
	{
		addToolStripMenuItem->Enabled = false;
		ButtonAdd->Enabled = false;
		this->label7->ForeColor = System::Drawing::Color::Red;
		this->label6->ForeColor = System::Drawing::Color::Red;
		this->label10->ForeColor = System::Drawing::Color::Red;
	}
	int Day = charTOint(textBoxArrDay->Text), Month = intMonth(textBoxArrMonth->Text), Year = charTOint(textBoxArrYear->Text);
	if (!Verification(Day, Month, Year))
	{
		addToolStripMenuItem->Enabled = false;
		ButtonAdd->Enabled = false;
		this->label7->ForeColor = System::Drawing::Color::Red;
		this->label6->ForeColor = System::Drawing::Color::Red;
		this->label10->ForeColor = System::Drawing::Color::Red;
	}
	else
	{
		addToolStripMenuItem->Enabled = true;
		ButtonAdd->Enabled = true;
		this->label7->ForeColor = System::Drawing::Color::Black;
		this->label6->ForeColor = System::Drawing::Color::Black;
		this->label10->ForeColor = System::Drawing::Color::Black;
	}
	if (textBoxArrDay->Text->Length == 0 ||
		textBoxArrMonth->Text->Length == 0 ||
		textBoxArrYear->Text->Length == 0)
	{
		addToolStripMenuItem->Enabled = false;
		ButtonAdd->Enabled = false;
		this->label7->ForeColor = System::Drawing::Color::Red;
		this->label6->ForeColor = System::Drawing::Color::Red;
		this->label10->ForeColor = System::Drawing::Color::Red;
	}
}


private: void Swapinlistbox(int indexA, int indexB)
	   {
		   ListViewItem^ item = listView1->Items[indexA];
		   listView1->Items->Remove(item);
		   listView1->Items->Insert(indexB, item);
	   }
private: System::Void buttonSorting_Click(System::Object^ sender, System::EventArgs^ e) {
	switch (this->comboBox1->SelectedIndex)
	{
	case 0: {//Name VIS 1
		if (radioButton1->Checked == true) {
			for (int i = 0; i < curSize - 1; i++) {
				for (int j = 0; j < curSize - i - 1; j++) {
					char* str1 = new char[SIZE_STRING];
					char* str2 = new char[SIZE_STRING];
					copyto(str1, listView1->Items[j]->SubItems[1]->Text, SIZE_STRING);
					copyto(str2, listView1->Items[j + 1]->SubItems[1]->Text, SIZE_STRING);
					if (strcmp(str1, str2) > 0) {
						Swapinlistbox(j, j + 1);
					}
				}
			}
		}
		else {//Сортировка по убыванию
			for (int i = curSize - 1; i > 0; i--) {
				for (int j = curSize - 1 - i; j >= 0; j--) {
					char* str1 = new char[SIZE_STRING];
					char* str2 = new char[SIZE_STRING];
					copyto(str1, listView1->Items[j]->SubItems[1]->Text, SIZE_STRING);
					copyto(str2, listView1->Items[j + 1]->SubItems[1]->Text, SIZE_STRING);
					if (strcmp(str1, str2) < 0) {
						Swapinlistbox(j, j + 1);
					}
				}
			}
		}
	}
	case 1: {//Price 1
		if (radioButton1->Checked == true) {
			for (int i = 0; i < curSize - 1; i++) {
				for (int j = 0; j < curSize - i - 1; j++) {
					int a = charTOint(listView1->Items[j]->SubItems[3]->Text);
					int b = charTOint(listView1->Items[j + 1]->SubItems[3]->Text);
					if (a > b) {
						Swapinlistbox(j, j + 1);
					}
				}
			}
		}
		else {//Сортировка по убыванию
			for (int i = curSize - 1; i > 0; i--) {
				for (int j = curSize - 1 - i; j >= 0; j--) {
					int a = charTOint(listView1->Items[j]->SubItems[3]->Text);
					int b = charTOint(listView1->Items[j + 1]->SubItems[3]->Text);
					if (a < b) {
						Swapinlistbox(j, j + 1);
					}
				}
			}
		}

		break;
	}
	case 2: {//Num 1
		if (radioButton1->Checked == true) {
			for (int i = 0; i < curSize - 1; i++) {
				for (int j = 0; j < curSize - i - 1; j++) {
					char* str1 = new char[SIZE_STRING];
					char* str2 = new char[SIZE_STRING];
					copyto(str1, listView1->Items[j]->SubItems[5]->Text, SIZE_STRING);
					copyto(str2, listView1->Items[j + 1]->SubItems[5]->Text, SIZE_STRING);
					if (strcmp(str1, str2) > 0) {
						Swapinlistbox(j, j + 1);
					}
				}
			}
		}
		else {//Сортировка по убыванию
			for (int i = curSize - 1; i > 0; i--) {
				for (int j = curSize - 1 - i; j >= 0; j--) {
					char* str1 = new char[SIZE_STRING];
					char* str2 = new char[SIZE_STRING];
					copyto(str1, listView1->Items[j]->SubItems[5]->Text, SIZE_STRING);
					copyto(str2, listView1->Items[j + 1]->SubItems[5]->Text, SIZE_STRING);
					if (strcmp(str1, str2) < 0) {
						Swapinlistbox(j, j + 1);
					}
				}
			}
		}

		break;
	}

	}
	
	for (int i = 0; i < curSize; i++)
	{
		this->listView1->Items[i]->Text = System::Convert::ToString(i + 1);
	}
}


private: System::Void ButtonNext_Click(System::Object^ sender, System::EventArgs^ e) {
	if (SearchInd == curSize)
	{
		SearchInd = 0;
		MessageBox::Show("No more matches found", "Searching for elements", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else
		SearchInd = Search(SeachText, SearchSubItemsInd, SearchInd) + 1;
		
}

};
};