#include "Calculator.h"
#include <QtMath>

Calculator::Calculator()
	: QObject(nullptr)
{
}
Calculator::~Calculator()
{
}

void Calculator::SetFirstValueAndOperation(double firstValue, Operation op)
{
	if (op == Operation::Add || op == Operation::Sub || op == Operation::Mul || op == Operation::Div)
	{
		this->firstValue = firstValue;
		this->op = op;
		firstValueSet = true;
	}
	else if (op == Operation::OneDivX)
	{
		if (firstValue != 0.0)
		{
			double result = 1.0 / firstValue;
			QString textResult = QString::number(result, 'f', 5);
			emit resultCalculated(textResult);
		}
		else
			emit resultCalculated("Division by zero");
	}
	else if (op == Operation::Pow2)
	{
		double result = qPow(firstValue, 2);
		QString textResult = QString::number(result, 'f', 5);
		emit resultCalculated(textResult);
	}
	else if (op == Operation::SqrtX)
	{
		if (firstValue >= 0.0)
		{
			double result = qSqrt(firstValue);
			QString textResult = QString::number(result, 'f', 5);
			emit resultCalculated(textResult);
		}
		else
			emit resultCalculated("Cannot evaluate square for negative value");
	}
}
void Calculator::Calculate(double secondValue)
{
	double result = 0.0;
	QString textResult;
	if (op == Operation::Add)
	{
		result = firstValue + secondValue;
	}
	else if (op == Operation::Sub)
	{
		result = firstValue - secondValue;
	}
	else if (op == Operation::Mul)
	{
		result = firstValue * secondValue;
	}
	else if (op == Operation::Div)
	{
		if (secondValue != 0.0)
			result = firstValue / secondValue;
		else
			textResult = "Division by zero";
	}
	if (textResult.isEmpty())
		textResult = QString::number(result, 'f', 5);
	emit resultCalculated(textResult);
}
void Calculator::Clear()
{
	firstValueSet = false;
}
