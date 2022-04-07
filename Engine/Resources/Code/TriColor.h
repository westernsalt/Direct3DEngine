/*!
 * \file TriColor.cpp
 * \date 2016/06/09 10:51
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

#ifndef TriColor_h__
#define TriColor_h__

#include "VIBuffer.h"

BEGIN(Engine)

class CGameObject;

class ENGINE_DLL CTriColor
	: public CVIBuffer
{
private:
	explicit CTriColor(LPDIRECT3DDEVICE9 pDevice);

public:
	virtual ~CTriColor(void);

public:
	virtual CResources* CloneResource(CGameObject* pGameObj);

public:
	virtual HRESULT CreateBuffer(void);
	virtual void Render(void);

public:
	static CTriColor* Create(LPDIRECT3DDEVICE9 pDevice);
};

END

#endif // TriColor_h__
