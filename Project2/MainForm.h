#pragma once

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;  // Added for SerialPort functionality

	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		int progress = 0;
		bool pump_is_running = false;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ProgressBar^ BoilerTank;
	private: System::Windows::Forms::Panel^ PumpIndicator;
	private: System::Windows::Forms::Panel^ ValveIndicator;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ PumpLabel;

	private: System::Windows::Forms::Label^ ValveLabel;
	private: System::Windows::Forms::Label^ label2;
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::Button^ SerialPort;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ RefreshPortsButton;
	private: System::Windows::Forms::TextBox^ receivedDataTextBox;
	private: System::Windows::Forms::Label^ receivedDataLabel;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TableLayoutPanel^ GraphTableLayout;

	private: System::Windows::Forms::Panel^ BoilerIndicator;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

		   String^ serialDataBuffer;  // Buffer to store received serial data

	public:
		MainForm(void)
		{
			InitializeComponent();
			BoilerTank->Value = progress;
			serialDataBuffer = "";

			// Populate COM ports when form loads
			RefreshComPorts();

			// Setup serial port event handlers
			serialPort1->DataReceived += gcnew SerialDataReceivedEventHandler(this, &MainForm::SerialPort1_DataReceived);
		}

	protected:
		~MainForm()
		{
			if (components)
				delete components;
		}



	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Button^ StartButton;

	private: System::Windows::Forms::Button^ StopButton;
	private: System::ComponentModel::IContainer^ components;






#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			   this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->StopButton = (gcnew System::Windows::Forms::Button());
			   this->StartButton = (gcnew System::Windows::Forms::Button());
			   this->SerialPort = (gcnew System::Windows::Forms::Button());
			   this->receivedDataTextBox = (gcnew System::Windows::Forms::TextBox());
			   this->receivedDataLabel = (gcnew System::Windows::Forms::Label());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->BoilerTank = (gcnew System::Windows::Forms::ProgressBar());
			   this->PumpIndicator = (gcnew System::Windows::Forms::Panel());
			   this->ValveIndicator = (gcnew System::Windows::Forms::Panel());
			   this->panel1 = (gcnew System::Windows::Forms::Panel());
			   this->BoilerIndicator = (gcnew System::Windows::Forms::Panel());
			   this->RefreshPortsButton = (gcnew System::Windows::Forms::Button());
			   this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->ValveLabel = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->PumpLabel = (gcnew System::Windows::Forms::Label());
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			   this->panel2 = (gcnew System::Windows::Forms::Panel());
			   this->GraphTableLayout = (gcnew System::Windows::Forms::TableLayoutPanel());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->tableLayoutPanel1->SuspendLayout();
			   this->panel1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   this->panel2->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // tableLayoutPanel1
			   // 
			   this->tableLayoutPanel1->ColumnCount = 3;
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   50)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   50)));
			   this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				   259)));
			   this->tableLayoutPanel1->Controls->Add(this->StopButton, 1, 0);
			   this->tableLayoutPanel1->Controls->Add(this->StartButton, 0, 0);
			   this->tableLayoutPanel1->Controls->Add(this->SerialPort, 2, 0);
			   this->tableLayoutPanel1->Location = System::Drawing::Point(37, 114);
			   this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			   this->tableLayoutPanel1->RowCount = 1;
			   this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			   this->tableLayoutPanel1->Size = System::Drawing::Size(923, 60);
			   this->tableLayoutPanel1->TabIndex = 2;
			   // 
			   // StopButton
			   // 
			   this->StopButton->BackColor = System::Drawing::Color::Red;
			   this->StopButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->StopButton->ForeColor = System::Drawing::Color::Transparent;
			   this->StopButton->Location = System::Drawing::Point(335, 3);
			   this->StopButton->Name = L"StopButton";
			   this->StopButton->Size = System::Drawing::Size(322, 54);
			   this->StopButton->TabIndex = 1;
			   this->StopButton->Text = L"Stop";
			   this->StopButton->UseVisualStyleBackColor = false;
			   this->StopButton->Click += gcnew System::EventHandler(this, &MainForm::StopButton_Click);
			   // 
			   // StartButton
			   // 
			   this->StartButton->BackColor = System::Drawing::Color::Lime;
			   this->StartButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->StartButton->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			   this->StartButton->Location = System::Drawing::Point(3, 3);
			   this->StartButton->Name = L"StartButton";
			   this->StartButton->Size = System::Drawing::Size(321, 54);
			   this->StartButton->TabIndex = 0;
			   this->StartButton->Text = L"Start";
			   this->StartButton->UseVisualStyleBackColor = false;
			   this->StartButton->Click += gcnew System::EventHandler(this, &MainForm::StartButton_Click);
			   // 
			   // SerialPort
			   // 
			   this->SerialPort->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			   this->SerialPort->Cursor = System::Windows::Forms::Cursors::Default;
			   this->SerialPort->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->SerialPort->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->SerialPort->Location = System::Drawing::Point(667, 3);
			   this->SerialPort->Name = L"SerialPort";
			   this->SerialPort->Size = System::Drawing::Size(253, 54);
			   this->SerialPort->TabIndex = 2;
			   this->SerialPort->Text = L"Connect";
			   this->SerialPort->UseVisualStyleBackColor = false;
			   this->SerialPort->Click += gcnew System::EventHandler(this, &MainForm::SerialPort_Click);
			   // 
			   // receivedDataTextBox
			   // 
			   this->receivedDataTextBox->BackColor = System::Drawing::SystemColors::ScrollBar;
			   this->receivedDataTextBox->Location = System::Drawing::Point(30, 534);
			   this->receivedDataTextBox->Multiline = true;
			   this->receivedDataTextBox->Name = L"receivedDataTextBox";
			   this->receivedDataTextBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			   this->receivedDataTextBox->Size = System::Drawing::Size(409, 150);
			   this->receivedDataTextBox->TabIndex = 14;
			   this->receivedDataTextBox->TextChanged += gcnew System::EventHandler(this, &MainForm::receivedDataTextBox_TextChanged);
			   // 
			   // receivedDataLabel
			   // 
			   this->receivedDataLabel->AutoSize = true;
			   this->receivedDataLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			   this->receivedDataLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->receivedDataLabel->Location = System::Drawing::Point(25, 506);
			   this->receivedDataLabel->Name = L"receivedDataLabel";
			   this->receivedDataLabel->Size = System::Drawing::Size(152, 25);
			   this->receivedDataLabel->TabIndex = 15;
			   this->receivedDataLabel->Text = L"Received Data";
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold));
			   this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->label1->Location = System::Drawing::Point(522, 292);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(122, 25);
			   this->label1->TabIndex = 1;
			   this->label1->Text = L"Boiler Tank";
			   // 
			   // BoilerTank
			   // 
			   this->BoilerTank->Location = System::Drawing::Point(542, 339);
			   this->BoilerTank->Name = L"BoilerTank";
			   this->BoilerTank->Size = System::Drawing::Size(155, 275);
			   this->BoilerTank->TabIndex = 0;
			   this->BoilerTank->Click += gcnew System::EventHandler(this, &MainForm::BoilerTank_Click);
			   // 
			   // PumpIndicator
			   // 
			   this->PumpIndicator->BackColor = System::Drawing::Color::Red;
			   this->PumpIndicator->Location = System::Drawing::Point(252, 480);
			   this->PumpIndicator->Name = L"PumpIndicator";
			   this->PumpIndicator->Size = System::Drawing::Size(85, 22);
			   this->PumpIndicator->TabIndex = 4;
			   // 
			   // ValveIndicator
			   // 
			   this->ValveIndicator->BackColor = System::Drawing::Color::Red;
			   this->ValveIndicator->Location = System::Drawing::Point(970, 652);
			   this->ValveIndicator->Name = L"ValveIndicator";
			   this->ValveIndicator->Size = System::Drawing::Size(81, 22);
			   this->ValveIndicator->TabIndex = 5;
			   // 
			   // panel1
			   // 
			   this->panel1->BackColor = System::Drawing::Color::LightSlateGray;
			   this->panel1->Controls->Add(this->BoilerIndicator);
			   this->panel1->Controls->Add(this->RefreshPortsButton);
			   this->panel1->Controls->Add(this->comboBox1);
			   this->panel1->Controls->Add(this->label2);
			   this->panel1->Controls->Add(this->tableLayoutPanel1);
			   this->panel1->Controls->Add(this->ValveLabel);
			   this->panel1->Controls->Add(this->label3);
			   this->panel1->Controls->Add(this->PumpLabel);
			   this->panel1->Controls->Add(this->ValveIndicator);
			   this->panel1->Controls->Add(this->PumpIndicator);
			   this->panel1->Controls->Add(this->BoilerTank);
			   this->panel1->Controls->Add(this->label1);
			   this->panel1->Controls->Add(this->pictureBox1);
			   this->panel1->Location = System::Drawing::Point(26, 27);
			   this->panel1->Name = L"panel1";
			   this->panel1->Size = System::Drawing::Size(1246, 719);
			   this->panel1->TabIndex = 3;
			   // 
			   // BoilerIndicator
			   // 
			   this->BoilerIndicator->BackColor = System::Drawing::Color::Red;
			   this->BoilerIndicator->Location = System::Drawing::Point(581, 673);
			   this->BoilerIndicator->Name = L"BoilerIndicator";
			   this->BoilerIndicator->Size = System::Drawing::Size(81, 22);
			   this->BoilerIndicator->TabIndex = 5;
			   // 
			   // RefreshPortsButton
			   // 
			   this->RefreshPortsButton->BackColor = System::Drawing::SystemColors::AppWorkspace;
			   this->RefreshPortsButton->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8, System::Drawing::FontStyle::Bold));
			   this->RefreshPortsButton->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->RefreshPortsButton->Location = System::Drawing::Point(979, 165);
			   this->RefreshPortsButton->Name = L"RefreshPortsButton";
			   this->RefreshPortsButton->Size = System::Drawing::Size(163, 35);
			   this->RefreshPortsButton->TabIndex = 13;
			   this->RefreshPortsButton->Text = L"Refresh Ports";
			   this->RefreshPortsButton->UseVisualStyleBackColor = false;
			   this->RefreshPortsButton->Click += gcnew System::EventHandler(this, &MainForm::RefreshPortsButton_Click);
			   // 
			   // comboBox1
			   // 
			   this->comboBox1->FormattingEnabled = true;
			   this->comboBox1->Location = System::Drawing::Point(979, 131);
			   this->comboBox1->Name = L"comboBox1";
			   this->comboBox1->Size = System::Drawing::Size(163, 28);
			   this->comboBox1->TabIndex = 12;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label2->Location = System::Drawing::Point(462, 55);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(297, 42);
			   this->label2->TabIndex = 11;
			   this->label2->Text = L"CONTROL PANEL";
			   this->label2->Click += gcnew System::EventHandler(this, &MainForm::label2_Click_1);
			   // 
			   // ValveLabel
			   // 
			   this->ValveLabel->AutoSize = true;
			   this->ValveLabel->BackColor = System::Drawing::Color::Transparent;
			   this->ValveLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->ValveLabel->Location = System::Drawing::Point(919, 531);
			   this->ValveLabel->Name = L"ValveLabel";
			   this->ValveLabel->Size = System::Drawing::Size(156, 25);
			   this->ValveLabel->TabIndex = 10;
			   this->ValveLabel->Text = L"Valve Indicator";
			   this->ValveLabel->Click += gcnew System::EventHandler(this, &MainForm::label4_Click);
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(270, 252);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(0, 20);
			   this->label3->TabIndex = 9;
			   this->label3->Click += gcnew System::EventHandler(this, &MainForm::label3_Click);
			   // 
			   // PumpLabel
			   // 
			   this->PumpLabel->AutoSize = true;
			   this->PumpLabel->BackColor = System::Drawing::Color::Transparent;
			   this->PumpLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->PumpLabel->Location = System::Drawing::Point(217, 319);
			   this->PumpLabel->Name = L"PumpLabel";
			   this->PumpLabel->Size = System::Drawing::Size(156, 25);
			   this->PumpLabel->TabIndex = 8;
			   this->PumpLabel->Text = L"Pump Indicator";
			   this->PumpLabel->Click += gcnew System::EventHandler(this, &MainForm::label2_Click);
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			   this->pictureBox1->Location = System::Drawing::Point(0, 100);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(1243, 619);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox1->TabIndex = 14;
			   this->pictureBox1->TabStop = false;
			   // 
			   // serialPort1
			   // 
			   this->serialPort1->BaudRate = 115200;
			   // 
			   // panel2
			   // 
			   this->panel2->BackColor = System::Drawing::Color::SlateGray;
			   this->panel2->Controls->Add(this->GraphTableLayout);
			   this->panel2->Controls->Add(this->label4);
			   this->panel2->Controls->Add(this->receivedDataTextBox);
			   this->panel2->Controls->Add(this->receivedDataLabel);
			   this->panel2->Location = System::Drawing::Point(1313, 27);
			   this->panel2->Name = L"panel2";
			   this->panel2->Size = System::Drawing::Size(473, 719);
			   this->panel2->TabIndex = 16;
			   // 
			   // GraphTableLayout
			   // 
			   this->GraphTableLayout->ColumnCount = 1;
			   this->GraphTableLayout->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				   50)));
			   this->GraphTableLayout->Location = System::Drawing::Point(30, 114);
			   this->GraphTableLayout->Name = L"GraphTableLayout";
			   this->GraphTableLayout->RowCount = 2;
			   this->GraphTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			   this->GraphTableLayout->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 190)));
			   this->GraphTableLayout->Size = System::Drawing::Size(409, 376);
			   this->GraphTableLayout->TabIndex = 17;
			   this->GraphTableLayout->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::tableLayoutPanel2_Paint);
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label4->Location = System::Drawing::Point(111, 55);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(253, 42);
			   this->label4->TabIndex = 16;
			   this->label4->Text = L"GRAPH PANEL";
			   this->label4->Click += gcnew System::EventHandler(this, &MainForm::label4_Click_1);
			   // 
			   // MainForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				   static_cast<System::Int32>(static_cast<System::Byte>(224)));
			   this->ClientSize = System::Drawing::Size(1828, 1046);
			   this->Controls->Add(this->panel2);
			   this->Controls->Add(this->panel1);
			   this->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->MinimumSize = System::Drawing::Size(1850, 830);
			   this->Name = L"MainForm";
			   this->Text = L"Boiler Instrumentation";
			   this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			   this->tableLayoutPanel1->ResumeLayout(false);
			   this->panel1->ResumeLayout(false);
			   this->panel1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   this->panel2->ResumeLayout(false);
			   this->panel2->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// Populate COM ports when form loads
		RefreshComPorts();
	}

	private: System::Void StartButton_Click(System::Object^ sender, System::EventArgs^ e) {

		// Send command to start pump if connected to serial
		if (serialPort1->IsOpen) {
			SendSerialCommand("START");
		}
		else {
			MessageBox::Show("Connect to port first.");
		}
	}

	private: System::Void StopButton_Click(System::Object^ sender, System::EventArgs^ e) {
		// Send command to stop pump if connected to serial
		if (serialPort1->IsOpen) {
			SendSerialCommand("SHUTDOWN");
		}
		else {
			MessageBox::Show("Connect to port first.");
		}
	}

		   void RefreshComPorts() {
			   // Get available port names and add to combo box
			   comboBox1->Items->Clear();
			   array<String^>^ ports = System::IO::Ports::SerialPort::GetPortNames();
			   comboBox1->Items->AddRange(ports);

			   // Select first port if available
			   if (ports->Length > 0) {
				   comboBox1->SelectedIndex = 0;
			   }
		   }

	private: System::Void RefreshPortsButton_Click(System::Object^ sender, System::EventArgs^ e) {
		RefreshComPorts();
	}

	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void SerialPort_Click(System::Object^ sender, System::EventArgs^ e) {
		// Connect to the selected COM port
		if (serialPort1->IsOpen)
		{
			// Disconnect
			serialPort1->Close();
			SerialPort->Text = "Connect";
		}
		else
		{
			// Connect
			try
			{
				// Check if a port is selected
				if (comboBox1->SelectedItem == nullptr)
				{
					MessageBox::Show("Please select a COM port before connecting.");
					return;
				}

				// Get selected port and connect
				String^ selectedPort = comboBox1->SelectedItem->ToString();
				serialPort1->PortName = selectedPort;
				serialPort1->BaudRate = 115200; // Set baud rate
				serialPort1->DataBits = 8;
				serialPort1->Parity = Parity::None;
				serialPort1->StopBits = StopBits::One;
				serialPort1->Handshake = Handshake::None;
				serialPort1->ReadTimeout = 5000;
				serialPort1->WriteTimeout = 5000;
				serialPort1->Open();

				// Update UI
				SerialPort->Text = "Disconnect";
			}
			catch (Exception^ ex)
			{
				// Handle exceptions (e.g., port not available)
				MessageBox::Show("Error: " + ex->Message);
			}
		}
	}

	// Handle data received from serial port
	private: System::Void SerialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e) {
		//try {
			if (serialPort1->BytesToRead > 0) {
				String^ data = serialPort1->ReadLine();
				Console::WriteLine("Received: " + data); // Log received data
				this->Invoke(gcnew Action<String^>(this, &MainForm::ProcessSerialData), data);
			}
		//}
		//catch (Exception^ ex) {
		//	this->Invoke(gcnew Action<String^>(this, &MainForm::ShowError), "Error reading serial data: " + ex->Message);
		//}
	}

	// Process the received serial data
	private: void ProcessSerialData(String^ data) {
		try {
			// Add the received data to the text box
			receivedDataTextBox->AppendText(data + Environment::NewLine);

			// Auto-scroll to bottom
			receivedDataTextBox->SelectionStart = receivedDataTextBox->Text->Length;
			receivedDataTextBox->ScrollToCaret();

			// Process the data based on new format
			// New format is space-separated: "temperature waterLevel pumpIndicator valveIndicator boilerIndicator"
			// Where temperature and waterLevel are floats, and indicators are 0 or 1 (boolean)
			array<String^>^ values = data->Trim()->Split(' ');

			// Check if we have all expected values
			if (values->Length >= 5) {
				// Parse temperature (float)
				float temperature;
				if (float::TryParse(values[0], System::Globalization::NumberStyles::Float,
					System::Globalization::CultureInfo::InvariantCulture, temperature)) {
					// Update temperature display or use as needed
					receivedDataTextBox->AppendText("Temperature: " + temperature.ToString("F2", System::Globalization::CultureInfo::InvariantCulture) + "°C\r\n");
				}
				else {
					receivedDataTextBox->AppendText("Warning: Failed to parse temperature value: " + values[0] + "\r\n");
				}

				// Parse water level (float)
				float waterLevel;
				if (float::TryParse(values[1], System::Globalization::NumberStyles::Float,
					System::Globalization::CultureInfo::InvariantCulture, waterLevel)) {
					// Update the boiler tank based on water level (0-100%)
					int level = Math::Min(Math::Max((int)Math::Round(waterLevel), 0), 100);
					BoilerTank->Value = level;
					receivedDataTextBox->AppendText("Water Level: " + waterLevel.ToString("F2", System::Globalization::CultureInfo::InvariantCulture) + "%\r\n");
				}
				else {
					receivedDataTextBox->AppendText("Warning: Failed to parse water level value: " + values[1] + "\r\n");
				}

				// Parse pump indicator (boolean - 0 or 1)
				int pumpState;
				if (Int32::TryParse(values[2], pumpState)) {
					pump_is_running = (pumpState == 1);
					PumpIndicator->BackColor = pump_is_running ? Color::Lime : Color::Red;
					receivedDataTextBox->AppendText("Pump: " + (pump_is_running ? "ON" : "OFF") + "\r\n");
				}

				// Parse valve indicator (boolean - 0 or 1)
				int valveState;
				if (Int32::TryParse(values[3], valveState)) {
					bool valve_is_open = (valveState == 1);
					ValveIndicator->BackColor = valve_is_open ? Color::Lime : Color::Red;
					receivedDataTextBox->AppendText("Valve: " + (valve_is_open ? "OPEN" : "CLOSED") + "\r\n");
				}

				// Parse boiler indicator (boolean - 0 or 1)
				int boilerState;
				if (Int32::TryParse(values[4], boilerState)) {
					bool boiler_is_on = (boilerState == 1);
					BoilerIndicator->BackColor = boiler_is_on ? Color::Lime : Color::Red;
					receivedDataTextBox->AppendText("Boiler: " + (boiler_is_on ? "ON" : "OFF") + "\r\n");
				}
				Console::WriteLine("Received Data: " + data);
				Console::WriteLine("Parsed Values: " + values->Length);
			}
			else {
				receivedDataTextBox->AppendText("Warning: Received data format does not match expected format.\r\n");
			}
		}
		catch (Exception^ ex) {
			ShowError("Error processing data: " + ex->Message);
		}
	}

	// Helper method to show errors
	private: void ShowError(String^ message) {
		MessageBox::Show(message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	// Method to send data to the serial port
	private: void SendSerialCommand(String^ command) {
		try {
			if (serialPort1->IsOpen) {
				// Add newline character if not present
				if (!command->EndsWith("\r\n")) {
					command += "\r\n";
				}
				serialPort1->Write(command);
			}
		}
		catch (Exception^ ex) {
			ShowError("Error sending command: " + ex->Message);
		}
	}
	private: System::Void label4_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BoilerTank_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tableLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void receivedDataTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}