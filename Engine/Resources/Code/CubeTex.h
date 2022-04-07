/*!
 * \file CubeTex.h
 * \date 2016/06/17 10:17
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

#ifndef CubeTex_h__
#define CubeTex_h__

#include "VIBuffer.h"

BEGIN(Engine)

class CGameObject;

class ENGINE_DLL CCubeTex
	: public CVIBuffer
{
private:
	explicit CCubeTex(LPDIRECT3DDEVICE9 pDevice);

public:
	virtual ~CCubeTex(void);

public:
	virtual CResources* CloneResource(CGameObject* pGameObj);

public:
	virtual HRESULT CreateBuffer(void);

public:
	static CCubeTex* Create(LPDIRECT3DDEVICE9 pDevice);
};

END


#endif // CubeTex_h__