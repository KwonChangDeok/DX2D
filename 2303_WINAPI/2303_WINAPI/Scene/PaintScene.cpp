#include "framework.h"
#include "PaintScene.h"

PaintScene::PaintScene()
{
	//_mouseRect = make_shared<RectCollider>(Vector2(400,400), Vector2(300,50));
	//_circle = make_shared<CircleCollider>(80, Vector2(400,400));
	_mouseCircle = make_shared<CircleCollider>(50, Vector2(400, 400));
	_rect = make_shared<RectCollider>(Vector2(600,400), Vector2(70,50));
}

PaintScene::~PaintScene()
{
}

void PaintScene::Update()
{
	Vector2 lerpPos = LERP(_mouseCircle->GetCenter(),mousePos,0.1f);

	_mouseCircle->SetCenter(lerpPos);
	//_mouseRect->SetCenter(lerpPos);


	if (_mouseCircle->IsCollision(_rect))
	{
		_mouseCircle->SetRed();
		_rect->SetRed();
	}
	else
	{
		_mouseCircle->SetGreen();
		_rect->SetGreen();
	}
}

void PaintScene::Render(HDC hdc)
{
	_mouseCircle->Render(hdc);
	//_circle->Render(hdc);

	//_mouseRect->Render(hdc);
	_rect->Render(hdc);
}
