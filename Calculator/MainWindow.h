#pragma once

#include <QWidget>
#include "ui_MainWindow.h"
#include "Calculator.h"

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	enum EditType
	{
		Digit_0,
		Digit_1,
		Digit_2,
		Digit_3,
		Digit_4,
		Digit_5,
		Digit_6,
		Digit_7,
		Digit_8,
		Digit_9,
		PlusMinus,
		Comma,
		Backspace,
	};
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	void onFormNumber(EditType editType);
	void onSetResult(QString result);
	double CommaToPoint(QString str);

	Ui::MainWindowUi ui;
	Calculator calc;
	QString textNumber;
};
