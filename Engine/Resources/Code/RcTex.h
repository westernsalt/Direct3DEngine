/*!
 * \file RcTex.h
 * \date 2016/06/13 10:32
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
#ifndef RcTex_h__
#define RcTex_h__

#include "VIBuffer.h"

BEGIN(Engine)

class CGameObject;

class ENGINE_DLL CRcTex
	: public CVIBuffer
{
private:
	explicit CRcTex(LPDIRECT3DDEVICE9 pDevice);

public:
	virtual ~CRcTex(void);

public:
	virtual CResources* CloneResource(CGameObject* pGameObj);

public:
	virtual HRESULT CreateBuffer(void);
	
public:
	static CRcTex* Create(LPDIRECT3DDEVICE9 pDevice);
};

END

#endif // RcTex_h__