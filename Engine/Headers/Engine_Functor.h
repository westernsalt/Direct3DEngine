/*!
 * \file Engine_Functor.h
 * \date 2015/05/01 15:33
 *
 * \author Administrator
 * Contact: user@company.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/

#ifndef Engine_Functor_h__
#define Engine_Functor_h__

namespace Engine
{
	class CDeleteObj
	{
	public:
		explicit CDeleteObj(void) {}
		~CDeleteObj(void) {}
	public: // operator
		template <typename T> void operator () (T& pInstance)
		{			
			if(NULL != pInstance)
			{
				delete pInstance;
				pInstance = NULL;
			}
		}
	};

	// ���������̳� ������
	class CDeleteMap
	{
	public:
		explicit CDeleteMap(void){}
		~CDeleteMap(void){}
	public: // operator	
		template <typename T> void operator () (T& Pair)
		{			
			if(NULL != Pair.second)
			{
				delete Pair.second;
				Pair.second = NULL;
			}
		}
	};
}

#endif // Engine_Functor_h__