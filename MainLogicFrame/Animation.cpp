#include "stdafx.h"
#include "Animation.h"

Animation::Animation(QWidget *parent)
	: QWidget(parent), m_IsShow(true),
	  m_Animation_Opacity( NULL ),
	  m_Animation_Geometry( NULL )
{
	
}

Animation::~Animation()
{
	delete m_Animation_Opacity;
	delete m_Animation_Geometry;
	m_Animation_Geometry = NULL;
	m_Animation_Opacity = NULL;
}

void Animation::showEvent(QShowEvent *event) {
	if (!m_IsShow)
		return;

	QParallelAnimationGroup* group = new QParallelAnimationGroup(this);
	group->addAnimation(m_Animation_Opacity);
	group->addAnimation(m_Animation_Geometry);
	group->start();
}

void Animation::setAnimation(bool isShow /*= true*/)
{
	m_IsShow = isShow;
}

void Animation::hideEvent(QHideEvent *event)
{
	closeAnimation(false);
}

void Animation::closeEvent(QCloseEvent *event)
{
	closeAnimation(true);
}

void Animation::closeAnimation(bool closeHide) {
	if (!m_IsShow) {
		qDebug("RETURN");
		return;
	}
	//���ùر�ʱ�Ķ���
	m_Animation_Opacity->setDuration(600);
	m_Animation_Opacity->setStartValue(1);
	m_Animation_Opacity->setEndValue(0);
	m_Animation_Opacity->setEasingCurve(QEasingCurve::Linear);
}

void Animation::InitAanimation()
{
	if (m_Animation_Opacity) {
		delete m_Animation_Opacity;
		m_Animation_Opacity = NULL;
	}
	if (m_Animation_Geometry) {
		delete m_Animation_Geometry;
		m_Animation_Geometry = NULL;
	}
	m_Animation_Opacity = new QPropertyAnimation(this, "windowOpacity");
	m_Animation_Geometry = new QPropertyAnimation(this, "geometry");

	m_Animation_Opacity->setDuration(600);
	m_Animation_Opacity->setStartValue(0);
	m_Animation_Opacity->setEndValue(1);
	m_Animation_Opacity->setEasingCurve(QEasingCurve::Linear);

	QDesktopWidget deskTop;
	m_Animation_Geometry->setDuration(500);
	m_Animation_Geometry->setStartValue(QRect(0, 0, deskTop.width(), deskTop.height()));
	m_Animation_Geometry->setEndValue(this->geometry());
}