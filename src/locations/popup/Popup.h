#pragma once

#include "cinder/Cinder.h"
#include "cinder/DataSource.h"
#include "cinder/ImageIo.h"
#include "cinder/Utilities.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/Texture.h"
#include "ButtonColor.h"
#include "FontStore.h"
#include "Params.h"

#include <boost/thread.hpp>
#include <boost/functional/hash.hpp>

	
class PopupBase
{
public:	
	// singleton implementation
	static PopupBase& getInstance() { static PopupBase tm; return tm; };


	void			draw();
	void			reset();
	
	void			start(int);
	void			setup();
	bool			isDrawing;

	ci::gl::Texture		screenShot;

	boost::signals2::signal<void(void )> closeEvent, sendEvent;
	ci::signals::connection	closeBtnSignal, sendBtnSignal;

	ButtonColor			*closeBtn, *sendBtn;

private:
	void	closeHandled();
	void	sendBtnHandled();
	void	cleanPopup();
	int		type;

};

inline PopupBase&	popup() { return PopupBase::getInstance(); };