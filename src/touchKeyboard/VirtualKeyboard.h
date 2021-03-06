#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/gl.h"
#include "cinder/ImageIO.h"
#include "cinder/Timeline.h"
#include "cinder/Json.h"
#include "ButtonTexture.h"

class VirtualKeyboard
{
public:

	static VirtualKeyboard& getInstance() { static VirtualKeyboard vk; return vk; };

	void setup(ci::Vec2f pos);
	void show();
	void hide();
	void draw();
	void update();
	void initKeyboard();
	void removeHandlers();
	void setPosition(ci::Vec2f _vec );
	std::string getLastCode();
	std::string getDisplayCode();

	boost::signals2::signal<void(void)> keyboardTouchSignal, keyboardClosedSignal, keyboardReadySignal;

	static ci::app::KeyEvent   imitate_ENTER_KEY_EVENT();
	static ci::app::KeyEvent   imitate_BACKSPACE_KEY_EVENT();
	static ci::app::MouseEvent inititateMouseEvent(ci::Vec2f _vec);

	bool	isMailCode();
	bool    isBackCode();
	bool	isSendCode();
	bool	isShiftCode();
	void	checkCapsLock();

	void MouseDown( ci::app::MouseEvent &event );
	void MouseUp( ci::app::MouseEvent &event );
	void alwaysCapsLock(bool value );

private :	
	std::vector<ButtonTex *> buttonsMainKeyboard, buttonsSecondKeyboard, buttonsRusMainKeyboard, *activeKeyboard;

	static std::string secondLineCharacters[10];
	static std::string thirdLineCharacters[10];
	static std::string fourthLineCharacters[9];

	static std::string secondLineCharacters2[10];
	static std::string thirdLineCharacters2[10];
	static std::string fourthLineCharacters2[10];


	static std::string secondLineCharacters3[11];
	static std::string thirdLineCharacters3[11];
	static std::string fourthLineCharacters3[10];

	static ci::Vec2f lineOffset1,lineOffset2,lineOffset3,lineOffset4, lineOffset5;
	static float _xOffset1,_xOffset2,_xOffset3,_xOffset4, _xOffset5;
	static int lineLength1, lineLength2, lineLength3, lineLength4;

	ci::app::WindowRef mainWindow;

	void KeyDown( ci::app::KeyEvent event  );

	void changeShiftMode();
	void changeKeyboardMode();


	std::string lastCode;
	std::string keyboardMode;

	bool isShiftDown, isKeyBoardChangeDown;


	ci::gl::Texture	 shiftTex1, shiftTex0;
	ci::gl::Texture	 changeKeyboardTex1, changeKeyboardTex2;

	ButtonTex   *shift, *changeKeyboardBtn;		

	ci::Vec2f  position;

	void closeKeyboard();

	ci::signals::connection KeyDownCon, MouseDownCon, MouseUpCon;

	enum KEYBOARD_LANG
	{
		ENG,
		RUS
	}activeLanguage;

	void changeLangMode();
	void offCapsLock();
	void onCapsLock();

	

	bool alwaysCaps;

};

inline VirtualKeyboard&	touchKeyboard() { return VirtualKeyboard::getInstance(); };