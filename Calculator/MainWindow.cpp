#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// connects
	connect(ui.button_0, &QPushButton::clicked, this, [=] { onFormNumber(Digit_0); });
	connect(ui.button_1, &QPushButton::clicked, this, [=] { onFormNumber(Digit_1); });
	connect(ui.button_2, &QPushButton::clicked, this, [=] { onFormNumber(Digit_2); });
	connect(ui.button_3, &QPushButton::clicked, this, [=] { onFormNumber(Digit_3); });
	connect(ui.button_4, &QPushButton::clicked, this, [=] { onFormNumber(Digit_4); });
	connect(ui.button_5, &QPushButton::clicked, this, [=] { onFormNumber(Digit_5); });
	connect(ui.button_6, &QPushButton::clicked, this, [=] { onFormNumber(Digit_6); });
	connect(ui.button_7, &QPushButton::clicked, this, [=] { onFormNumber(Digit_7); });
	connect(ui.button_8, &QPushButton::clicked, this, [=] { onFormNumber(Digit_8); });
	connect(ui.button_9, &QPushButton::clicked, this, [=] { onFormNumber(Digit_9); });

	connect(ui.button_plus_minus, &QPushButton::clicked, this, [=] { onFormNumber(PlusMinus); });
	connect(ui.button_comma, &QPushButton::clicked, this, [=] { onFormNumber(Comma); });
	connect(ui.button_backspace, &QPushButton::clicked, this, [=] { onFormNumber(Backspace); });

	connect(ui.button_add, &QPushButton::clicked, this, [=] { calc.SetFirstValueAndOperation(CommaToPoint(textNumber), Calculator::Operation::Add); textNumber = "0"; });
	connect(ui.button_sub, &QPushButton::clicked, this, [=] { calc.SetFirstValueAndOperation(CommaToPoint(textNumber), Calculator::Operation::Sub); textNumber = "0"; });
	connect(ui.button_mul, &QPushButton::clicked, this, [=] { calc.SetFirstValueAndOperation(CommaToPoint(textNumber), Calculator::Operation::Mul); textNumber = "0"; });
	connect(ui.button_div, &QPushButton::clicked, this, [=] { calc.SetFirstValueAndOperation(CommaToPoint(textNumber), Calculator::Operation::Div); textNumber = "0"; });
	connect(ui.button_1_div_x, &QPushButton::clicked, this, [=] { calc.SetFirstValueAndOperation(CommaToPoint(textNumber), Calculator::Operation::OneDivX); });
	connect(ui.button_pow_2, &QPushButton::clicked, this, [=] { calc.SetFirstValueAndOperation(CommaToPoint(textNumber), Calculator::Operation::Pow2); });
	connect(ui.button_sqrt_x, &QPushButton::clicked, this, [=] { calc.SetFirstValueAndOperation(CommaToPoint(textNumber), Calculator::Operation::SqrtX); });
	
	connect(ui.button_clear, &QPushButton::clicked, this, [=] { calc.Clear(); textNumber = "0";});
	connect(ui.button_equal, &QPushButton::clicked, this, [=] {calc.Calculate(CommaToPoint(textNumber)); });
	
	connect(&calc, &Calculator::resultCalculated, this, &MainWindow::onSetResult);

	calc.Clear();
	textNumber = "0";
}

void MainWindow::onFormNumber(EditType editType)
{
	if (textNumber == "0" && editType >= 0 && editType <= 9)
		textNumber = "";
	// digits
	if (editType == Digit_0)
		textNumber += "0";
	else if (editType == Digit_1)
		textNumber += "1";
	else if (editType == Digit_2)
		textNumber += "2";
	else if (editType == Digit_3)
		textNumber += "3";
	else if (editType == Digit_4)
		textNumber += "4";
	else if (editType == Digit_5)
		textNumber += "5";
	else if (editType == Digit_6)
		textNumber += "6";
	else if (editType == Digit_7)
		textNumber += "7";
	else if (editType == Digit_8)
		textNumber += "8";
	else if (editType == Digit_9)
		textNumber += "9";
	// +/-
	else if (editType == PlusMinus)
	{
		if (textNumber[0] == '-')
			textNumber.remove('-');
		else if (textNumber != "0")
			textNumber = '-' + textNumber;
	}
	// ,
	else if (editType == Comma)
	{
		if (textNumber.indexOf(',') == -1)
			textNumber += ',';
		else if (textNumber.indexOf(',') == textNumber.length() - 1)
			textNumber.remove(',');
	}
	// Backspace
	else if (editType == Backspace)
	{
		if (textNumber == "-0,")
			textNumber = "0";
		else if (textNumber.length() == 1)
			textNumber = "0";
		else if (textNumber.length() == 2 && textNumber[0] == '-')
			textNumber = "0";
		else if (textNumber != "0")
			textNumber.chop(1);
	}
	ui.edit_display->setText(textNumber);
}
void MainWindow::onSetResult(QString result)
{
	ui.edit_display->setText(result);
	textNumber = result;
}
double MainWindow::CommaToPoint(QString str)
{
	return str.replace(',', '.').toDouble();
}
