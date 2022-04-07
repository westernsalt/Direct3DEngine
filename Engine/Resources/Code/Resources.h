/*!
 * \file Resources.h
 * \date 2016/06/10 10:39
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

#ifndef Resources_h__
#define Resources_h__

#include "Component.h"

BEGIN(Engine)

class CGameObject;

class ENGINE_DLL CResources
	: public CComponent
{
protected:
	explicit CResources(LPDIRECT3DDEVICE9 pDevice);

public:
	virtual ~CResources(void);

public:
	virtual CResources* CloneResource(CGameObject* pGameObj) PURE;

protected:
	void Release(void);

protected:
	WORD*		m_pwRefCnt;

protected:
	LPDIRECT3DDEVICE9		m_pDevice;
};

END

#endif // Resources_h__