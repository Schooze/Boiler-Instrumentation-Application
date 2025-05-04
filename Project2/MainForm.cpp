#include "MainForm.h"

using namespace Project2;
using namespace System::Windows::Forms::DataVisualization::Charting;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    // Create and run the form
    Application::Run(gcnew MainForm());
    return 0;
}
