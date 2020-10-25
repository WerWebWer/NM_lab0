#pragma once
#include <math.h>
#include <string>
#include "Header.h"



namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace ZedGraph;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: ZedGraph::ZedGraphControl^  zedGraphControl1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ I;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ X;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ H_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ V_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ V_i_i;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Vi_Vii;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ LOC;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ViUTCH;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ DIV;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ MUL;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox4;

	private: System::Windows::Forms::TextBox^  textBox5;

	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: int status;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;

	private:
		
		int numTask = 0;
		bool loc = false;


	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Xi;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ hi;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Vi;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Делений;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Удвоений;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::CheckBox^ checkBox2;

	protected:
	private: System::ComponentModel::IContainer^  components;

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
			this->components = (gcnew System::ComponentModel::Container());
			this->zedGraphControl1 = (gcnew ZedGraph::ZedGraphControl());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->I = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Xi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->hi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Vi = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->V_i_i = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Vi_Vii = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ViUTCH = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Делений = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Удвоений = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->LOC = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// zedGraphControl1
			// 
			this->zedGraphControl1->Location = System::Drawing::Point(36, 261);
			this->zedGraphControl1->Name = L"zedGraphControl1";
			this->zedGraphControl1->ScrollGrace = 0;
			this->zedGraphControl1->ScrollMaxX = 0;
			this->zedGraphControl1->ScrollMaxY = 0;
			this->zedGraphControl1->ScrollMaxY2 = 0;
			this->zedGraphControl1->ScrollMinX = 0;
			this->zedGraphControl1->ScrollMinY = 0;
			this->zedGraphControl1->ScrollMinY2 = 0;
			this->zedGraphControl1->Size = System::Drawing::Size(501, 327);
			this->zedGraphControl1->TabIndex = 0;
			this->zedGraphControl1->Load += gcnew System::EventHandler(this, &MyForm::zedGraphControl1_Load);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(36, 149);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(142, 29);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Вычислить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->I, this->Xi,
					this->hi, this->Vi, this->V_i_i, this->Vi_Vii, this->LOC, this->ViUTCH, this->Делений, this->Удвоений
			});
			this->dataGridView1->Location = System::Drawing::Point(559, 261);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(503, 327);
			this->dataGridView1->TabIndex = 2;
			// 
			// I
			// 
			this->I->HeaderText = L"I";
			this->I->Name = L"I";
			this->I->ReadOnly = true;
			this->I->Width = 50;
			// 
			// 
			// LOC
			// 
			this->LOC->HeaderText = L"ОЛП";
			this->LOC->Name = L"LOC";
			this->LOC->ReadOnly = true;
			this->LOC->Width = 50;
			// Xi
			// 
			this->Xi->HeaderText = L"Xi";
			this->Xi->Name = L"Xi";
			this->Xi->ReadOnly = true;
			this->Xi->Width = 50;
			// 
			// hi
			// 
			this->hi->HeaderText = L"hi";
			this->hi->Name = L"hi";
			this->hi->ReadOnly = true;
			this->hi->Width = 50;
			// 
			// Vi
			// 
			this->Vi->HeaderText = L"Vi";
			this->Vi->Name = L"Vi";
			this->Vi->ReadOnly = true;
			this->Vi->Width = 50;
			// 
			// V_i_i
			// 
			this->V_i_i->HeaderText = L"V^i";
			this->V_i_i->Name = L"V_i_i";
			this->V_i_i->ReadOnly = true;
			this->V_i_i->Width = 50;
			// 
			// Vi_Vii
			// 
			this->Vi_Vii->HeaderText = L"Vi-V^i";
			this->Vi_Vii->Name = L"Vi_Vii";
			this->Vi_Vii->ReadOnly = true;
			this->Vi_Vii->Width = 50;
			// 
			// ViUTCH
			// 
			this->ViUTCH->HeaderText = L"Vi(уточ)";
			this->ViUTCH->Name = L"ViUTCH";
			this->ViUTCH->ReadOnly = true;
			this->ViUTCH->Width = 50;
			// 
			// Делений
			// 
			this->Делений->HeaderText = L"Делений";
			this->Делений->Name = L"Делений";
			this->Делений->ReadOnly = true;
			this->Делений->Width = 50;
			// 
			// Удвоений
			// 
			this->Удвоений->HeaderText = L"Удвоений";
			this->Удвоений->Name = L"Удвоений";
			this->Удвоений->ReadOnly = true;
			this->Удвоений->Width = 50;
			// 
			// LOC
			// 
			this->LOC->Name = L"LOC";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(34, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Xmin";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(37, 82);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(48, 20);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"0";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(34, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Xmax";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(37, 120);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(49, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"1";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(275, 137);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Начальный шаг";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(278, 153);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(61, 20);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"0,1";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(36, 213);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(142, 29);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Zoom";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(129, 187);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(49, 20);
			this->textBox4->TabIndex = 13;
			this->textBox4->Text = L"1,2";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(36, 187);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(48, 20);
			this->textBox5->TabIndex = 11;
			this->textBox5->Text = L"0";
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Test", L"Main 1", L"Main 2" });
			this->comboBox1->Location = System::Drawing::Point(36, 32);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 15;
			this->comboBox1->Text = L"Test";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(278, 71);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(61, 20);
			this->textBox6->TabIndex = 16;
			this->textBox6->Text = L"0,000001";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(275, 55);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(187, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"Контроль локальной прогрешности";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(91, 82);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(48, 20);
			this->textBox7->TabIndex = 18;
			this->textBox7->Text = L"1";
			this->textBox7->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox7_TextChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(96, 68);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(18, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"U.";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(89, 190);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(34, 13);
			this->label8->TabIndex = 20;
			this->label8->Text = L"Zoom";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(32, 9);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(67, 20);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Задача";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(275, 16);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(152, 13);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Точность выходв нa границу";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(278, 32);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 22;
			this->textBox8->Text = L"0.000001";
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(278, 114);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 20);
			this->textBox9->TabIndex = 23;
			this->textBox9->Text = L"100";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(275, 98);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(150, 13);
			this->label9->TabIndex = 24;
			this->label9->Text = L"Максимальное число шагов";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(531, 11);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(73, 20);
			this->label10->TabIndex = 25;
			this->label10->Text = L"Справка";
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::label10_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(535, 39);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(0, 13);
			this->label11->TabIndex = 26;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(346, 74);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 27;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(278, 196);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(20, 20);
			this->textBox10->TabIndex = 28;
			this->textBox10->Text = L"1";
			this->textBox10->Visible = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(275, 180);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(13, 13);
			this->label12->TabIndex = 29;
			this->label12->Text = L"a";
			this->label12->Visible = false;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(301, 180);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(20, 13);
			this->label13->TabIndex = 30;
			this->label13->Text = L"U\'.";
			this->label13->Visible = false;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(304, 196);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(20, 20);
			this->textBox11->TabIndex = 31;
			this->textBox11->Text = L"0";
			this->textBox11->Visible = false;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Location = System::Drawing::Point(278, 224);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(118, 17);
			this->checkBox2->TabIndex = 32;
			this->checkBox2->Text = L"Фазовый портрет";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1123, 652);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->zedGraphControl1);
			this->Name = L"MyForm";
			this->Text = L"Graph";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		double f1(double x){
			return sin(x);
		}

		double f2(double x) {
			return sin(2 * x);
		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		int n = 0;
		int countMul = 0;
		int countDev = 0;
		double maxH = 0;
		double minH = 999999;
		double maxE = 0;

		GraphPane^ panel = zedGraphControl1->GraphPane;
		panel->CurveList->Clear();
		PointPairList^ f1_list = gcnew ZedGraph::PointPairList(); // Численное (с помощью рк4)
		PointPairList^ f2_list = gcnew ZedGraph::PointPairList(); // Истинное (просто через функцию посчитать)

		// Интервал, где есть данные
		double xmin = Convert::ToDouble(textBox1->Text);
		double xmax = Convert::ToDouble(textBox2->Text);
		// Шаг по Х
		double h = Convert::ToDouble(textBox3->Text);
		double _h = Convert::ToDouble(textBox3->Text);
		// Начальные условия по U
		double u = Convert::ToDouble(textBox7->Text);
		double _u = Convert::ToDouble(textBox7->Text);
		//
		double a = Convert::ToDouble(textBox10->Text);
		//
		double _u2 = Convert::ToDouble(textBox11->Text);
		// Максимальная погрешность
		double e_loc = Convert::ToDouble(textBox6->Text);
		// Максимальное количество шагов
		int maxI = Convert::ToDouble(textBox9->Text);

		// Границы графика
		double xmin_limit = xmin - 0.1;
		double xmax_limit = xmax + 0.1;

		Pos pos(xmin, u);
		pos.u2 = _u2;
		pos.a = a;
		double x = xmin;
		int i = 0; // Счетчик итераций

		dataGridView1->Rows->Clear();

		do {
			//Добавление на график
			f1_list->Add(((checkBox2->Checked == true && numTask == 2) ? pos.u2 : pos.x), pos.u);
			//Печать в таблицу
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = i; 			
			dataGridView1->Rows[i]->Cells[1]->Value = pos.x;
			dataGridView1->Rows[i]->Cells[2]->Value = h;
			dataGridView1->Rows[i]->Cells[3]->Value = pos.u;
			dataGridView1->Rows[i]->Cells[4]->Value = pos.v;
			dataGridView1->Rows[i]->Cells[5]->Value = abs(pos.u - pos.v);
			dataGridView1->Rows[i]->Cells[6]->Value = numTask != 0 ? pos.e : abs(func_test_(pos.x, pos.u)-pos.u);//abs(pos.u - pos.v)/32;
			dataGridView1->Rows[i]->Cells[7]->Value = func_test_(pos.x,pos.u);
			dataGridView1->Rows[i]->Cells[8]->Value = 0;
			dataGridView1->Rows[i]->Cells[9]->Value = 0;
			pos.e = numTask == 0 ? abs(func_test_(pos.x, pos.u) - pos.u) : pos.e;
			if (x != xmax) {
				if (x + h > xmax) {
					//if (abs(xmax - x - h) < 0.0000001)
						h = xmax - x;
						x = xmax;
					//else x += h;
				}
				else x += h;
			}
			else x += h;

			auto get = start(pos, h, a, numTask, checkBox1->Checked, e_loc); //first - pos | second - h */ 2
			pos = get.first;
			if (get.second > 0) {
				countMul += get.second;
				dataGridView1->Rows[i]->Cells[9]->Value = get.second;
				h *= 2;
			}
			if (get.second < 0) { 
				countDev -= get.second;
				dataGridView1->Rows[i]->Cells[8]->Value = -get.second;
				/*if (pos.u > 2.29) h *= 2;
				else */
					for (int i = 0; i < -get.second; i++) {
						h /= 2;
					}
			}
			if (maxE < pos.e) maxE = pos.e;
			if (h > maxH) maxH = h;
			if (h < minH) minH = h;

			zedGraphControl1->AxisChange();
			zedGraphControl1->Invalidate();
			i++;
		} while (((checkBox1->Checked) ? (x <= xmax) : (x < xmax)) && i < maxI+1); //TODO: ГАВНО ПОЛНОЕ ПЕРЕДЕЛАТЬ

		label11->Text = "n = " + (i - 1) + "\nЧисло удвоений: " + countMul + "\nЧисло делений: " + countDev + "\nМаксимальный шаг " + maxH + "\nМинимальный шаг: " + minH + "\nМаксимальная ошибка шаг: " + maxE;

		if (numTask == 0) {
			double x = xmin;
			u = _u;
			h = _h;
			i = 0;
			do {
				f2_list->Add(x, u);
				x += h;
				u = func_test_(x, u);
				i++;
			} while (x <= xmax && i < maxI + 1);
			LineItem Curve2 = panel->AddCurve("Точное решение", f2_list, Color::Blue, SymbolType::None);
		}

		zedGraphControl1->AxisChange();
		zedGraphControl1->Invalidate();
		LineItem Curve1 = panel->AddCurve("Численное решение", f1_list, Color::Red,SymbolType::None);
		//"n \nЧисло удвоений: \nЧисло делений: \nМаксимальный шаг: \nМинимальный шаг: "





		// Устанавливаем интересующий нас интервал по оси X
		panel->XAxis->Scale->Min = xmin_limit;
		panel->XAxis->Scale->Max = xmax_limit;
		panel->YAxis->Scale->Min = xmin_limit;
		panel->YAxis->Scale->Max = xmax_limit;


	}
	private: System::Void zedGraphControl1_Load(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
	GraphPane^ panel = zedGraphControl1->GraphPane;
	double xmin = Convert::ToDouble(textBox5->Text);
	double xmax = Convert::ToDouble(textBox4->Text);

	// Устанавливаем интересующий нас интервал по оси X
	panel->XAxis->Scale->Min = xmin;
	panel->XAxis->Scale->Max = xmax;
	panel->YAxis->Scale->Min = xmin;
	panel->YAxis->Scale->Max = xmax;

	// Вызываем метод AxisChange (), чтобы обновить данные об осях. 
	// В противном случае на рисунке будет показана только часть графика, 
	// которая умещается в интервалы по осям, установленные по умолчанию
	zedGraphControl1->AxisChange();
	// Обновляем график
	zedGraphControl1->Invalidate();

}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	numTask = comboBox1->SelectedIndex;
	if (numTask == 2) {
		textBox10->Visible = true;
		label12->Visible = true;
		label13->Visible = true;
		textBox11->Visible = true;
		checkBox2->Visible = true;
	} else {
		textBox10->Visible = false;
		label12->Visible = false;
		label13->Visible = false;
		textBox11->Visible = false;
		checkBox2->Visible = false;
	}
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox7_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox8_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
//private: System::Void checkBox1_CheckStateChanged(System::Object^ sender, System::EventArgs^ e) {
//	loc = comboBox1->CheckState
//}
};
}
