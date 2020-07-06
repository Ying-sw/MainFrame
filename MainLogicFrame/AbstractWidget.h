#ifndef  __ABSTRACTWIDGET__
#define  __ABSTRACTWIDGET__
#include "MainFrame_global.h"
#include "SignalQueue.h"

class MAINFRAME_EXPORT AbstractWidget : public QWidget
{
	Q_OBJECT
public:
	/// \brief ���캯��
	/// \param[in] parent ������
	AbstractWidget(QWidget* parent = 0);

	/// \brief ��������������ֹ�ڴ�й©
	virtual ~AbstractWidget();

	/// \brief ����Ϣ����
	/// �ں����ڲ�ִ��get���������յ���Ϣ�������ȴ�����
	virtual void OnMessage();

	/// \brief ���ڹر��¼�
	virtual void OnClose();

	/// \brief ���log
	/// \param[in] strTgtLog ��־����
	void Log(const QString& strTgtLog);

	/// \brief ����ֱ��ʴ�С�����ҷ��ؼ����ĺ��ʴ�С
	/// \param[in] size ԭ���Ĵ�С
	/// \retval ���ؼ�����ֵ
	int CalculateResolution(const int& size);

	/// \brief ���ݸ����Ĳ��ʵ���ж��Ƿ�������
	/// \param[in] strPlug �������
	/// \param[in] strInstance ���ʵ������
	bool PlugIsRuning(const QString& strPlug, const QString& strInstance);

	/// \brief �����ź�
	/// \param[in] sig �ź�����
	/// \param[in] arg �źŲ���
	void SendSIG(Signal_ sig, void* arg);
};

#endif
