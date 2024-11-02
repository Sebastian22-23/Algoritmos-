#pragma once
namespace GAMEJAM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	private:
		CController* controller;
		Graphics^ g;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
		   Bitmap^ buffer;

	public:
		MyForm2(void)
		{
			InitializeComponent();
			this->SetStyle(ControlStyles::UserPaint | ControlStyles::AllPaintingInWmPaint | ControlStyles::OptimizedDoubleBuffer, true);
			this->UpdateStyles();

			g = this->CreateGraphics();
			controller = new CController(g, 0);

			// Inicializa el buffer gráfico
			buffer = gcnew Bitmap(this->Width, this->Height);
		}

	protected:
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
			if (buffer)
			{
				delete buffer;
			}
			delete controller;
		}

	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->SuspendLayout();
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Interval = 20;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm2::timer1_Tick);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::Red;
			   this->label1->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->ForeColor = System::Drawing::Color::Black;
			   this->label1->Location = System::Drawing::Point(163, 690);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(112, 24);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Carrito 1:";
			   this->label1->Click += gcnew System::EventHandler(this, &MyForm2::label1_Click);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::Color::Red;
			   this->label2->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->ForeColor = System::Drawing::Color::Black;
			   this->label2->Location = System::Drawing::Point(546, 690);
			   this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(112, 24);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Carrito 2:";
			   this->label2->Click += gcnew System::EventHandler(this, &MyForm2::label2_Click);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->BackColor = System::Drawing::Color::Red;
			   this->label3->Font = (gcnew System::Drawing::Font(L"MS UI Gothic", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label3->ForeColor = System::Drawing::Color::Black;
			   this->label3->Location = System::Drawing::Point(930, 690);
			   this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(112, 24);
			   this->label3->TabIndex = 2;
			   this->label3->Text = L"Carrito 3:";
			   this->label3->Click += gcnew System::EventHandler(this, &MyForm2::label3_Click);
			   // 
			   // MyForm2
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1240, 784);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->ForeColor = System::Drawing::Color::White;
			   this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			   this->Name = L"MyForm2";
			   this->Text = L"MyForm2";
			   this->TransparencyKey = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				   static_cast<System::Int32>(static_cast<System::Byte>(0)));
			   this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			   this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm2::MyForm2_Paint);
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

	private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
		buffer = gcnew Bitmap(this->Width, this->Height);
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		// Mueve y dibuja en el buffer
		Graphics^ g = Graphics::FromImage(buffer);
		g->Clear(Color::White);  // Limpia el fondo del buffer

		controller->moverTodos2(g);
		controller->dibujarTodos(g);
		controller->contarTiposDeCarro();

		label1->Text = "Carrito 1: " + controller->getContadorCarro1();
		label2->Text = "Carrito 2: " + controller->getContadorCarro2();
		label3->Text = "Carrito 3: " + controller->getContadorCarro3();

		this->Invalidate();  // Esto provocará un repaint
		delete g;
	}

	private: System::Void MyForm2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		// Dibuja el buffer en el formulario
		e->Graphics->DrawImage(buffer, 0, 0);
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
