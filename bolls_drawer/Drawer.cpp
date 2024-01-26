#include "pch.h"
#include "Drawer.h"


#define _USE_MATH_DEFINES


IMPLEMENT_DYNAMIC(Drawer, CStatic)

Drawer::Drawer()
{	
	GdiplusStartupInput si;
	GdiplusStartup(&token, &si, NULL);
}

Drawer::~Drawer()
{	
	GdiplusShutdown(token);
}

BEGIN_MESSAGE_MAP(Drawer, CStatic)

END_MESSAGE_MAP()

void Drawer::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{	
	double ItemWidth = lpDrawItemStruct->rcItem.right - lpDrawItemStruct->rcItem.left,
		ItemHeight = lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top;
	
	//параметры графика в мировых кооринатах
	double top = 2 * br->GetR();
	double bottom = 0;
	double left = 0;
	double right = br->GetLenght();

	double steplenY = (top - bottom) / 10,
		steplenX = (right - left) / 10;

	double xScale = ItemWidth / (right - left);
	double yScale = -ItemHeight / (top - bottom);

	Bitmap Image(ItemWidth, ItemHeight);
	Graphics gr(&Image);
	gr.Clear(Color::White);

	//сглаживание
	gr.SetSmoothingMode(SmoothingModeAntiAlias);

	//преобразование мира(переход к координатам самого графика
	Matrix matr;
	matr.Scale(xScale, (yScale + 1)); //маштабирование
	matr.Translate(0, -top / 2); //перенос начала координат

	gr.SetTransform(&matr);

	Pen BackGroundPen(Color::DarkGray, 0.005);
	Pen pen(Color::Black, 0.006);
	Pen pen2(Color::Blue, 0.006);

	Pen StickPen(Color::CornflowerBlue, 0.02);
	SolidBrush brush(Color::Black);
	SolidBrush PlatformBrush(Color::Crimson);
	Gdiplus::Font font((L"Times New Roman"), 14, FontStyle::FontStyleRegular, UnitPixel);


	//–азметка
	for (int i = 0; i < 10; i++)
	{
		//горизонтальна€
		gr.DrawLine(&BackGroundPen, PointF(0, top / 2 - i * steplenY), PointF(right, top / 2 - i * steplenY));

		//вертикальна€
		gr.DrawLine(&BackGroundPen, PointF(i * steplenX, top / 2), PointF(i * steplenX, - top / 2));
	}

	//Ѕольшие оси
	//горизонтальна€
	gr.DrawLine(&pen, PointF(0, 0), PointF(right, 0));

	//вертикальна€
	gr.DrawLine(&pen, PointF(0, top / 2), PointF(0, -top / 2));

	//границы €мы
	//gr.DrawLine(&pen2, PointF(R, top), PointF(R, 0));
	//gr.DrawLine(&pen2, PointF(-R, top), PointF(-R, 0));

	gr.ResetTransform();

	//подписи к ос€м
	for (int i = 0; i < 11; i++)
	{
		CString str;

		//по Y
		str.Format(L"%.2f", top / 2 - i * steplenY);
		PointF strPoint(0, top / 2 - i * steplenY);
		matr.TransformPoints(&strPoint);
		gr.DrawString(str, str.GetLength() + 1, &font, strPoint, &brush);

		//по X
		str.Format(L"%.2f",  i * steplenX);
		strPoint.X = i * steplenX;
		strPoint.Y = 0;
		matr.TransformPoints(&strPoint);
		gr.DrawString(str, str.GetLength() + 1, &font, strPoint, &brush);
	}

	gr.SetTransform(&matr);

	float r = br->GetR();
	float bWidth = 2 * r;
	float bHeight = 2 * r;
	float* mas = br->GetMas();

	//ќтрисовка шариков
	for (int i = 0; i < br->GetSize(); i++)
		gr.DrawEllipse(&pen2, RectF(PointF(mas[i] - r, -r), SizeF(bWidth, bHeight)));
	
	
	Graphics grnew(lpDrawItemStruct->hDC);
	grnew.DrawImage(&Image, 0, 0);	
}



