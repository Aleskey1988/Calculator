#pragma once

#include <QObject>

class Calculator : public QObject
{
	Q_OBJECT

public:
	enum Operation
	{
		Default,
		Add,
		Sub,
		Mul,
		Div,
		OneDivX,
		Pow2,
		SqrtX
	};

	Calculator();
	~Calculator();

	void SetFirstValueAndOperation(double firstValue, Operation op);
	void Calculate(double secondValue);
	void Clear();

signals:
	void resultCalculated(QString result);

private:
	QString simplifyResult(double result);

	double firstValue = 0.0;
	bool firstValueSet = false;
	Operation op;
};
