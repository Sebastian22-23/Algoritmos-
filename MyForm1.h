#pragma once
#include "CController.h"
namespace GAMEJAM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
		static int Second = 0;
		static int Minute = 0;
		String^ Sec;
		String^ Min;

	private:
		CController* contr;
		Graphics^ g;
	private: System::Windows::Forms::Label^ lblTime;
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
		   Bitmap^ buffer;

	public:
		MyForm1(void)
		{
			InitializeComponent();
			this->SetStyle(ControlStyles::UserPaint | ControlStyles::AllPaintingInWmPaint | ControlStyles::OptimizedDoubleBuffer, true);
			this->UpdateStyles();

			g = this->CreateGraphics();
			contr = new CController(g);

			// Inicializa el buffer gráfico
			buffer = gcnew Bitmap(this->Width, this->Height);
		}

	protected:
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
			if (buffer)
			{
				delete buffer;
			}
			delete contr;
		}

	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->lblTime = (gcnew System::Windows::Forms::Label());
			   this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 1000;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm1::timer1_Tick);
			   // 
			   // lblTime
			   // 
			   this->lblTime->AutoSize = true;
			   this->lblTime->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->lblTime->Location = System::Drawing::Point(33, 9);
			   this->lblTime->Name = L"lblTime";
			   this->lblTime->Size = System::Drawing::Size(46, 22);
			   this->lblTime->TabIndex = 0;
			   this->lblTime->Text = L"0:0";
			   this->lblTime->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			   // 
			   // timer2
			   // 
			   this->timer2->Enabled = true;
			   this->timer2->Tick += gcnew System::EventHandler(this, &MyForm1::timer2_Tick);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::Transparent;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::Color::Crimson;
			   this->label1->Location = System::Drawing::Point(1154, 192);
			   this->label1->Name = L"label1";
			   this->label1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->label1->Size = System::Drawing::Size(81, 69);
			   this->label1->TabIndex = 1;
			   this->label1->Text = L"M";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::Color::Transparent;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->ForeColor = System::Drawing::Color::Crimson;
			   this->label2->Location = System::Drawing::Point(1154, 281);
			   this->label2->Name = L"label2";
			   this->label2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->label2->Size = System::Drawing::Size(71, 69);
			   this->label2->TabIndex = 2;
			   this->label2->Text = L"E";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->BackColor = System::Drawing::Color::Transparent;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->ForeColor = System::Drawing::Color::Crimson;
			   this->label3->Location = System::Drawing::Point(1154, 378);
			   this->label3->Name = L"label3";
			   this->label3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->label3->Size = System::Drawing::Size(68, 69);
			   this->label3->TabIndex = 3;
			   this->label3->Text = L"T";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->BackColor = System::Drawing::Color::Transparent;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->ForeColor = System::Drawing::Color::Crimson;
			   this->label4->Location = System::Drawing::Point(1154, 463);
			   this->label4->Name = L"label4";
			   this->label4->RightToLeft = System::Windows::Forms::RightToLeft::No;
			   this->label4->Size = System::Drawing::Size(71, 69);
			   this->label4->TabIndex = 4;
			   this->label4->Text = L"A";
			   // 
			   // MyForm1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1240, 784);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->lblTime);
			   this->DoubleBuffered = true;
			   this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->Name = L"MyForm1";
			   this->Text = L"CARRERA";
			   this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm1::MyForm1_Paint);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {

		buffer = gcnew Bitmap(this->Width, this->Height);

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		Second++;

		if (Second == 60)
		{
			Second = 0;
			Minute++;
		}

		Sec = Convert::ToString(Second);
		Min = Convert::ToString(Minute);
		lblTime->Text = Min + ":" + Sec;





	}
	private: System::Void MyForm1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		e->Graphics->DrawImage(buffer, 0, 0);

	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = Graphics::FromImage(buffer);
		g->Clear(Color::White);  // Limpia el fondo del buffer
		contr->moverTodos(g);
		contr->dibujarTodos(g);
		contr->dibujarMeta(g);
		this->Invalidate();

		if (contr->colisionmeta() == true)
		{
			this->Close();
		}
		delete g;
	}
	};
}
